#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	int fd;
	t_map map;
	t_args args;

	ft_memset(&args, 0, sizeof(t_args));
	ft_memset(&map, 0, sizeof(t_map));
	// if (argc == 3)
	//     tobmp();
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (ft_printf("Error fd\n"));
	init_args(fd, &args, &map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1920, 1080, "Cub3d");
	mlx_loop(map.mlx);
	// start_game(&map);
	close(fd);
	int i = 0;
	if (args.path)
	{
		while (i < 4)
		{
			if (args.path[i])
				free(args.path[i]);
			i++;
		}
	}
	// if (!parse(&map, fd))
	//     return(0);
}