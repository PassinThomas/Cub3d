/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:05:14 by tpassin           #+#    #+#             */
/*   Updated: 2025/03/05 17:36:42 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calcul_ray(t_map *map, t_ray *ray, int x)
{
	double	camera;

	camera = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydir.x = map->camera.dir.x + map->camera.plane.x * camera;
	ray->raydir.y = map->camera.dir.y + map->camera.plane.y * camera;
}

void	init_ray_delta(t_ray *ray, t_map *map)
{
	ray->mapx = (int)map->camera.pos.x;
	ray->mapy = (int)map->camera.pos.y;
	if (ray->raydir.x == 0)
		ray->deltadist.x = 1e30;
	else
		ray->deltadist.x = fabs(1 / ray->raydir.x);
	if (ray->raydir.y == 0)
		ray->deltadist.y = 1e30;
	else
		ray->deltadist.y = fabs(1 / ray->raydir.y);
	ray->mapx = (int)map->camera.pos.x;
	ray->mapy = (int)map->camera.pos.y;
	if (ray->raydir.x == 0)
		ray->deltadist.x = 1e30;
	else
		ray->deltadist.x = fabs(1 / ray->raydir.x);
	if (ray->raydir.y == 0)
		ray->deltadist.y = 1e30;
	else
		ray->deltadist.y = fabs(1 / ray->raydir.y);
}

void	calcul_step(t_ray *ray, t_map *map)
{
	init_ray_delta(ray, map);
	if (ray->raydir.x < 0)
	{
		ray->stepx = -1;
		ray->sidedist.x = (map->camera.pos.x - ray->mapx) * ray->deltadist.x;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedist.x = (ray->mapx + 1.0 - map->camera.pos.x)
			* ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->stepy = -1;
		ray->sidedist.y = (map->camera.pos.y - ray->mapy) * ray->deltadist.y;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedist.y = (ray->mapy + 1.0 - map->camera.pos.y)
			* ray->deltadist.y;
	}
}

void	dda(t_map *map, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (map->map[ray->mapy][ray->mapx] == 1)
		{
			hit = 1;
			break ;
		}
	}
}
