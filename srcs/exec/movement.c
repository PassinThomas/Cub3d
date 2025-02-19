/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:10:12 by tpassin           #+#    #+#             */
/*   Updated: 2025/01/23 18:29:56 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_map *map, double move_speed)
{
	if (map->keyboard[KEY_W])
	{
		if (!map->map[(int)(map->camera.pos.y + map->camera.dir.y
				* (move_speed))][(int)map->camera.pos.x])
			map->camera.pos.y += map->camera.dir.y * move_speed;
		if (!map->map[(int)map->camera.pos.y][(int)(map->camera.pos.x
			+ map->camera.dir.x * (move_speed))])
			map->camera.pos.x += map->camera.dir.x * move_speed;
	}
}

void	move_backward(t_map *map, double move_speed)
{
	if (map->keyboard[KEY_S])
	{
		if (!map->map[(int)(map->camera.pos.y - map->camera.dir.y
				* (move_speed))][(int)map->camera.pos.x])
			map->camera.pos.y -= map->camera.dir.y * move_speed;
		if (!map->map[(int)map->camera.pos.y][(int)(map->camera.pos.x
			- map->camera.dir.x * (move_speed))])
			map->camera.pos.x -= map->camera.dir.x * move_speed;
	}
}

void	move_left(t_map *map, double move_speed)
{
	if (map->keyboard[KEY_A])
	{
		if (!map->map[(int)(map->camera.pos.y - map->camera.dir.x
				* (move_speed))][(int)map->camera.pos.x])
			map->camera.pos.y -= map->camera.dir.x * move_speed;
		if (!map->map[(int)map->camera.pos.y][(int)(map->camera.pos.x
			+ map->camera.dir.y * (move_speed))])
			map->camera.pos.x += map->camera.dir.y * move_speed;
	}
}

void	move_right(t_map *map, double move_speed)
{
	if (map->keyboard[KEY_D])
	{
		if (!map->map[(int)(map->camera.pos.y + map->camera.dir.x
				* (move_speed))][(int)map->camera.pos.x])
			map->camera.pos.y += map->camera.dir.x * move_speed;
		if (!map->map[(int)map->camera.pos.y][(int)(map->camera.pos.x
			- map->camera.dir.y * (move_speed))])
			map->camera.pos.x -= map->camera.dir.y * move_speed;
	}
}

void	handle_movement(t_map *map)
{
	double	move_speed;

	move_speed = MOVE_SPEED;
	move_forward(map, move_speed);
	move_backward(map, move_speed);
	move_left(map, move_speed);
	move_right(map, move_speed);
	rotate_left(map);
	rotate_right(map);
}
