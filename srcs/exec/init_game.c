/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:21:40 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/11 15:05:07 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_pos_player(t_map *map)
{
	map->player.pos_x = map->player.pos.x * CELL + CELL / 2;
	map->player.pos_y = map->player.pos.y * CELL + CELL / 2;
	if (map->player.pos.face == 'N')
	{
		map->player.dir_x = 0;
		map->player.dir_y = 1;
	}
	if (map->player.pos.face == 'S')
	{
		map->player.dir_x = 0;
		map->player.dir_y = -1;
	}
	if (map->player.pos.face == 'E')
	{
		map->player.dir_x = 1;
		map->player.dir_y = 0;
	}
	if (map->player.pos.face == 'W')
	{
		map->player.dir_x = -1;
		map->player.dir_y = 0;
	}
}
