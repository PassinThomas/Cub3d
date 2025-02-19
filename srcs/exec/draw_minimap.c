/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:14:11 by tpassin           #+#    #+#             */
/*   Updated: 2025/01/29 17:22:19 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_loop(t_img *img, int start_x, int start_y, int color)
{
	int	x;
	int	y;
	int	size;

	y = 0;
	if (img->player == 1)
		size = SIZE_PLAYER;
	else
		size = MINIMAP_SCALE;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_img *img, t_map *map)
{
	int	player_x;
	int	player_y;

	player_x = (int)(map->camera.pos.x * MINIMAP_SCALE);
	player_y = (int)(map->camera.pos.y * MINIMAP_SCALE);
	img->player = 1;
	draw_loop(img, player_x, player_y, RED);
}

void	draw_minimap(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->img.player = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 1)
				draw_loop(&map->img, x * (int)MINIMAP_SCALE, y
					* (int)MINIMAP_SCALE, SALMON);
			else
				draw_loop(&map->img, x * (int)MINIMAP_SCALE, y
					* (int)MINIMAP_SCALE, BLACK);
			x++;
		}
		y++;
	}
	draw_player(&map->img, map);
}
