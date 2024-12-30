/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:36:38 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/30 17:03:52 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_map *map)
{
	if (keycode < 203)
		map->keyboard[keycode] = 1;
	if (keycode == LEFT)
		map->left_pressed = true;
	if (keycode == RIGHT)
		map->right_pressed = true;
	if (keycode == ESC)
		ft_close_window(map);
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	if (keycode < 203)
		map->keyboard[keycode] = 0;
	if (keycode == LEFT)
		map->left_pressed = false;
	if (keycode == RIGHT)
		map->right_pressed = false;
	return (0);
}

void	rotate_left(t_map *map)
{
	double	oldir;
	double	old_planex;
	double	rot_speed;

	rot_speed = ROT_SPEED;
	if (map->left_pressed)
	{
		oldir = map->camera.dir.x;
		map->camera.dir.x = map->camera.dir.x * cos(-rot_speed)
			- map->camera.dir.y * sin(-rot_speed);
		map->camera.dir.y = oldir * sin(-rot_speed) + map->camera.dir.y
			* cos(-rot_speed);
		old_planex = map->camera.plane.x;
		map->camera.plane.x = map->camera.plane.x * cos(-rot_speed)
			- map->camera.plane.y * sin(-rot_speed);
		map->camera.plane.y = old_planex * sin(-rot_speed) + map->camera.plane.y
			* cos(-rot_speed);
	}
}

void	rotate_right(t_map *map)
{
	double	oldir;
	double	rot_speed;
	double	old_planex;

	rot_speed = ROT_SPEED;
	if (map->right_pressed)
	{
		oldir = map->camera.dir.x;
		map->camera.dir.x = map->camera.dir.x * cos(rot_speed)
			- map->camera.dir.y * sin(rot_speed);
		map->camera.dir.y = oldir * sin(rot_speed) + map->camera.dir.y
			* cos(rot_speed);
		old_planex = map->camera.plane.x;
		map->camera.plane.x = map->camera.plane.x * cos(rot_speed)
			- map->camera.plane.y * sin(rot_speed);
		map->camera.plane.y = old_planex * sin(rot_speed) + map->camera.plane.y
			* cos(rot_speed);
	}
}
