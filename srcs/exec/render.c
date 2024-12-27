/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:22:54 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/27 20:51:51 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// double	calculate_perp_wall_dist(t_ray ray, t_map *map)
// {
// 	if (ray.side == 0)
// 		return ((ray.mapx - map->camera.pos.x + (1 - ray.stepx) / 2)
// 			/ ray.raydir.x);
// 	else
// 		return ((ray.mapy - map->camera.pos.y + (1 - ray.stepy) / 2)
// 			/ ray.raydir.y);
// }

// int	get_wall_color(t_ray ray)
// {
// 	int	color;

// 	if (ray.side == 0)
// 	{
// 		if (ray.raydir.x > 0)
// 			color = RED; // red for East
// 		else
// 			color = GREEN; // green for West
// 	}
// 	else
// 	{
// 		if (ray.raydir.y > 0)
// 			color = BLUE; // blue for South
// 		else
// 			color = WHITE; // white for North
// 	}
// 	return (color);
// }

// // void	draw_vert_line(t_img *img, int x, t_ray ray)
// // {
// // 	int	y;

// // 	if (ray.start < 0)
// // 		ray.start = 0;
// // 	if (ray.end >= WIN_HEIGHT)
// // 		ray.end = WIN_HEIGHT - 1;
// // 	y = ray.start;
// // 	while (y <= ray.end)
// // 	{
// // 		if (my_mlx_pixel_put(img, x, y, ray.color))
// // 			return ;
// // 		y++;
// // 	}
// // }

// void	draw_vert_line(t_img *img, int x, t_ray ray)
// {
// 	int	y;
// 	int	color;

// 	if (ray.start < 0)
// 		ray.start = 0;
// 	if (ray.end >= WIN_HEIGHT)
// 		ray.end = WIN_HEIGHT - 1;
// 	y = ray.start;
// 	while (y <= ray.end)
// 	{
// 		color = get_texture_color();
// 		if (my_mlx_pixel_put(img, x, y, color))
// 			return ;
// 		y++;
// 	}
// }

// void	render(t_map *map)
// {
// 	int		x;
// 	t_ray	ray;

// 	x = 0;
// 	while (x < WIN_WIDTH)
// 	{
// 		calcul_ray(map, &ray, x);
// 		calcul_step(&ray, map);
// 		dda(map, &ray);
// 		ray.perp_walldist = calculate_perp_wall_dist(ray, map);
// 		ray.lineheight = (int)(WIN_HEIGHT / ray.perp_walldist);
// 		ray.start = -ray.lineheight / 2 + WIN_HEIGHT / 2;
// 		ray.end = ray.lineheight / 2 + WIN_HEIGHT / 2;
// 		ray.color = get_wall_color(ray);
// 		draw_vert_line(&map->img, x, ray);
// 		x++;
// 	}
// }

void	calculate_texture_coords(t_ray ray, t_map *map, double *wall_x,
		int *tex_x)
{
	if (ray.side == 0)
		*wall_x = map->camera.pos.y + ray.perp_walldist * ray.raydir.y;
	else
		*wall_x = map->camera.pos.x + ray.perp_walldist * ray.raydir.x;
	*wall_x -= floor(*wall_x);
	*tex_x = (int)(*wall_x * TEXTURE_WIDTH);
	if (ray.side == 0 && ray.raydir.x < 0)
		*tex_x = TEXTURE_WIDTH - *tex_x - 1;
	if (ray.side == 1 && ray.raydir.y < 0)
		*tex_x = TEXTURE_WIDTH - *tex_x - 1;
}

t_img	*select_texture(t_ray ray, t_map *map)
{
	if (ray.side == 0)
	{
		if (ray.raydir.x > 0)
			return (&map->text[3]);
		return (&map->text[2]);
	}
	if (ray.raydir.y > 0)
		return (&map->text[1]);
	return (&map->text[0]);
}

double	calculate_perp_wall_dist(t_ray ray, t_map *map)
{
	if (ray.side == 0)
		return ((ray.mapx - map->camera.pos.x + (1 - ray.stepx) / 2)
			/ ray.raydir.x);
	return ((ray.mapy - map->camera.pos.y + (1 - ray.stepy) / 2)
		/ ray.raydir.y);
}

void	draw_vert_line(t_img *img, int x, t_ray ray, t_map *map)
{
	int		y;
	t_img	*texture;

	if (ray.start < 0)
		ray.start = 0;
	if (ray.end >= WIN_HEIGHT)
		ray.end = WIN_HEIGHT - 1;
	calculate_texture_coords(ray, map, &map->text->wall_x, &map->text->tex_x);
	texture = select_texture(ray, map);
	map->text->step = (double)TEXTURE_HEIGHT / ray.lineheight;
	map->text->tex_pos = (ray.start - WIN_HEIGHT / 2 + ray.lineheight / 2)
		* map->text->step;
	y = ray.start;
	while (y <= ray.end)
	{
		map->text->tex_y = (int)map->text->tex_pos & (TEXTURE_HEIGHT - 1);
		map->text->tex_pos += map->text->step;
		map->text->color = get_texture_color(texture, map->text->tex_x,
				map->text->tex_y);
		if (my_mlx_pixel_put(img, x, y, map->text->color))
			return ;
		y++;
	}
}

void	render(t_map *map)
{
	int		x;
	t_ray	ray;

	x = 0;
	draw_floor_ceiling(&map->img, map);
	while (x < WIN_WIDTH)
	{
		calcul_ray(map, &ray, x);
		calcul_step(&ray, map);
		dda(map, &ray);
		ray.perp_walldist = calculate_perp_wall_dist(ray, map);
		ray.lineheight = (int)(WIN_HEIGHT / ray.perp_walldist);
		ray.start = -ray.lineheight / 2 + WIN_HEIGHT / 2;
		ray.end = ray.lineheight / 2 + WIN_HEIGHT / 2;
		draw_vert_line(&map->img, x, ray, map);
		x++;
	}
}
