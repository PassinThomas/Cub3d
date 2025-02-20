/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:02:29 by emehdaou          #+#    #+#             */
/*   Updated: 2025/02/20 20:16:10 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_cardinals(char **tab, t_args *args, int index)
{
	int	i;

	i = 0;
	while (tab[1][i])
	{
		if (!ft_isprint(tab[1][i]))
			return (ft_printf("Error path printable\n"), 1);
		i++;
	}
	args->path[index] = ft_strdup(tab[1]);
	return (0);
}

int	store_rgb(char **tab, t_args *args, int index)
{
	int	i;
	int	j;

	i = 0;
	tab = tab + 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (4);
			j++;
		}
		if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
			return (1);
		if (index == 4)
			args->floor[i] = ft_atoi(tab[i]);
		else
			args->celling[i] = ft_atoi(tab[i]);
		i++;
	}
	return (0);
}

int	check_args(char **file, t_args *args, t_map *map)
{
	int			i;
	int			index;
	char		**tmp;
	static char	*tab[6] = {"NO", "SO", "WE", "EA", "F", "C"};

	i = 0;
	while (i < 6)
	{
		tmp = ft_split(file[i], " ,");
		if (!tmp)
			return (free_tab(tmp), free_args(args),
				ft_printf("Error taille arguments\n"), 1);
		index = in_tab(tmp[0], tab);
		if (index == -1)
			return (printf("Error Cardinals\n"), free_tab(tmp), 1);
		if (index < 4 && (len_tab(tmp) != 2 || check_cardinals(tmp, args,
					index)))
			return (printf("Error cardinals"), free_tab(tmp), 1);
		else if (index >= 4 && (len_tab(tmp) != 4 || store_rgb(tmp, args,
					index)))
			return (printf("Error rgb\n"), free_tab(tmp), free_args(args), 2);
		free_tab(tmp);
		i++;
	}
	return (0);
}

int	init_args(int fd, t_args *args, t_map *map)
{
	char	*str;
	int		flag;

	flag = 0;
	str = recup_gnl(fd);
	if (!close(fd) || !str)
		return (ft_printf("Error\n%s\n", ERR), 1);
	map->file = ft_split(str, "\n");
	free(str);
	if (!map->file)
		return (1);
	if (check_args(map->file, args, map))
		return (free_tab(map->file), 2);
	if (check_map(map->file, args, map))
		return (5);
	return (0);
}
