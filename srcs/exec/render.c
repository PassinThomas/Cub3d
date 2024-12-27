/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:22:54 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/27 01:30:32 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	calculate_perp_wall_dist(t_ray ray, t_map *map)
{
	if (ray.side == 0)
		return ((ray.mapx - map->camera.pos.x + (1 - ray.stepx) / 2)
			/ ray.raydir.x);
	else
		return ((ray.mapy - map->camera.pos.y + (1 - ray.stepy) / 2)
			/ ray.raydir.y);
}

int	get_wall_color(t_ray ray)
{
	int	color;

	if (ray.side == 0)
	{
		if (ray.raydir.x > 0)
			color = RED; // red for East
		else
			color = GREEN; // green for West
	}
	else
	{
		if (ray.raydir.y > 0)
			color = BLUE; // blue for South
		else
			color = WHITE; // white for North
	}
	return (color);
}

void	draw_vert_line(t_img *img, int x, t_ray ray)
{
	int	y;

	if (ray.start < 0)
		ray.start = 0;
	if (ray.end >= WIN_HEIGHT)
		ray.end = WIN_HEIGHT - 1;
	y = ray.start;
	while (y <= ray.end)
	{
		if (my_mlx_pixel_put(img, x, y, ray.color))
			return ;
		y++;
	}
}

void	render(t_map *map)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		calcul_ray(map, &ray, x);
		calcul_step(&ray, map);
		dda(map, &ray);
		ray.perp_walldist = calculate_perp_wall_dist(ray, map);
		ray.lineheight = (int)(WIN_HEIGHT / ray.perp_walldist);
		ray.start = -ray.lineheight / 2 + WIN_HEIGHT / 2;
		ray.end = ray.lineheight / 2 + WIN_HEIGHT / 2;
		ray.color = get_wall_color(ray);
		draw_vert_line(&map->img, x, ray);
		x++;
	}
}
