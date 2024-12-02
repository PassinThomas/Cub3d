/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:55:27 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/02 18:43:56 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	t_args	args;
	int		i;

	ft_memset(&args, 0, sizeof(t_args));
	// if (argc == 3)
	//     tobmp();
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (ft_printf("Error fd\n"));
	init_args(fd, &args, &map);
	// map.mlx = mlx_init();
	// map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	// mlx_loop(map.mlx);
	// start_game(&map);
	close(fd);
	i = 0;
	if (args.path)
	{
		while (i < 4)
		{
			if (args.path[i])
				free(args.path[i]);
			i++;
		}
	}
	return (0);
}
