/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:25:22 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/27 17:57:26 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	main_loop(t_map *map)
{
	handle_movement(map);
	mlx_destroy_image(map->mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel,
			&map->img.line_length, &map->img.endian);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	render(map);
	return (0);
}

void	start_game(t_map *map)
{
	map->map = init_map(map);
	map->mlx = mlx_init();
	if (init_data(map))
	{
		free_all(map);
		ft_close_window(map);
	}
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	map->img.img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel,
			&map->img.line_length, &map->img.endian);
	init_pos_player(map);
	mlx_hook(map->win, 2, 1L << 0, key_press, map);
	mlx_hook(map->win, 3, 1L << 1, key_release, map);
	mlx_loop_hook(map->mlx, main_loop, map);
	mlx_loop(map->mlx);
}
