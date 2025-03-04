/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:55:27 by tpassin           #+#    #+#             */
/*   Updated: 2025/03/04 14:04:32 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_int_tab(int **tab, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_close_window(t_map *map)
{
	free_text(map);
	if (map->img.img)
		mlx_destroy_image(map->mlx, map->img.img);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	if (map->file)
		free_tab(map->file);
	free_all(map);
	exit(0);
	return (0);
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	free_args(&map->args);
	free_int_tab(map->map, map->height);
}

int	**init_map(t_map *map)
{
	int	x;
	int	y;
	int	**new;

	y = 0;
	new = malloc(sizeof(int *) * map->height);
	if (!new)
		return (NULL);
	while (y < map->height)
	{
		new[y] = malloc(sizeof(int) * map->width);
		if (!new[y])
			return (NULL);
		x = 0;
		while (map->file[y + 6][x] && x < map->width)
		{
			if (map->file[y + 6][x] == '1')
				new[y][x] = 1;
			else
				new[y][x] = 0;
			x++;
		}
		y++;
	}
	return (new);
}

int	main(int argc, char **argv, char **env)
{
	int		fd;
	t_map	map;
	t_args	args;

	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(args.path, 0, sizeof(t_args));
	if (!env[0])
		return (ft_printf("Error empty env\n"), 1);
	if (argc != 2)
		return (ft_printf("Error args\n"), 1);
	if (!is_cub(argv[1]))
		return (ft_printf("Error extension\n"), 1);
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (ft_printf("Error fd\n"), 1);
	if (init_args(fd, &args, &map))
		return (1);
	map.args = args;
	start_game(&map);
	close(fd);
	return (0);
}
