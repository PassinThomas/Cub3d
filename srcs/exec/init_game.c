/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:21:40 by tpassin           #+#    #+#             */
/*   Updated: 2025/01/02 17:47:19 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	player_pos(t_map *map)
{
	map->camera.pos.x = map->pos.x + 0.5;
	map->camera.pos.y = map->pos.y + 0.5;
}

void	init_pos_player(t_map *map)
{
	player_pos(map);
	if (map->pos.face == 'N')
	{
		map->camera.dir.x = 0;
		map->camera.dir.y = -1;
		map->camera.plane.x = 0.66;
	}
	if (map->pos.face == 'S')
	{
		map->camera.dir.x = 0;
		map->camera.dir.y = 1;
		map->camera.plane.x = -0.66;
	}
	if (map->pos.face == 'E')
	{
		map->camera.dir.x = 1;
		map->camera.dir.y = 0;
		map->camera.plane.y = 0.66;
	}
	if (map->pos.face == 'W')
	{
		map->camera.dir.x = -1;
		map->camera.dir.y = 0;
		map->camera.plane.y = -0.66;
	}
}
