/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:55:27 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/30 17:14:48 by tpassin          ###   ########.fr       */
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

void	ft_close_window(t_map *map)
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
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	if (map->args.path && map->args.path[i])
	{
		while (i < 4)
		{
			if (map->args.path[i])
				free(map->args.path[i]);
			i++;
		}
	}
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
		while (x < map->width)
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

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	t_args	args;

	ft_memset(&map, 0, sizeof(t_map));
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (ft_printf("Error fd\n"));
	if (init_args(fd, &args, &map))
		return (1);
	map.args = args;
	start_game(&map);
	close(fd);
	return (0);
}
