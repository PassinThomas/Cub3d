/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:55:27 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/11 18:26:12 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	if (map->args.path)
	{
		while (i < 4)
		{
			if (map->args.path[i])
				free(map->args.path[i]);
			i++;
		}
	}
	free_tab(map->tab);
}

int	ft_close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	free(map->mlx);
	exit(0);
}

void	bresenham(t_map *data, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		mlx_pixel_put(data->mlx, data->win, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

// Fonction qui sera appelée à chaque mouvement de souris
int	mouse_move(int x, int y, t_map *map)
{
	map->mouse_x = x;
	map->mouse_y = y;
	// Effacer l'écran en redessinant l'arrière-plan
	// Tracer la ligne du joueur vers la position de la souris
	// Blanc
	// Mettre à jour la position du joueur si nécessaire
	// (cela peut être ajusté selon l'implémentation de la position du joueur)
	return (0);
}

int	run_game(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == '1')
				draw_loop(map, j * CELL, i * CELL, CELL, SALMON);
			j++;
		}
		i++;
	}
	draw_loop(map, map->player.pos_x, map->player.pos_y, 3, RED);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	bresenham(map, map->player.pos_x, map->player.pos_y, map->mouse_x,
		map->mouse_y, 0xFFFFFF);
	return (0);
}

void	start_game(t_map *map)
{
	init_pos_player(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	map->img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel,
			&map->line_length, &map->endian);
	mlx_loop_hook(map->mlx, run_game, map);
	mlx_hook(map->win, 6, 1L << 6, mouse_move, map);
	mlx_loop(map->mlx);
}

void	map_realloc(t_map *map)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	while (map->tab[i])
	{
		len = ft_strlen(map->tab[i]);
		if (len < map->width)
		{
			new = malloc(map->width + 1);
			ft_strcpy(new, map->tab[i]);
			ft_memset(new + len, '1', map->width - len);
			new[map->width] = '\0';
			free(map->tab[i]);
			map->tab[i] = new;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	t_args	args;
	int		i;

	ft_memset(&map, 0, sizeof(t_map));
	// if (argc == 3)
	//     tobmp();
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (ft_printf("Error fd\n"));
	if (init_args(fd, &args, &map))
		return (1);
	// map_realloc(&map);
	// printf("[%d][%d]\n", map.player.x, map.player.y);
	// print_tab(map.tab);
	start_game(&map);
	free_all(&map);
	close(fd);
	return (0);
}
