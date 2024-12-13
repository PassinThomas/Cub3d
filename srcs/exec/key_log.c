/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:36:38 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/11 15:39:35 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_map *map)
{
	printf("%d\n", keycode);
	if (keycode < 203)
		map->keyboard[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	if (keycode < 203)
		map->keyboard[keycode] = 0;
	return (0);
}