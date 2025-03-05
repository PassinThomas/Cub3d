/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:02:29 by emehdaou          #+#    #+#             */
/*   Updated: 2025/03/05 16:24:45 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_empty(char *str)
{
	int			i;
	int			j;
	int			cnt;
	char		*tmp;
	static char	*tab[6] = {"NO", "SO", "WE", "EA", "F ", "C "};

	i = 0;
	cnt = 0;
	while (cnt < 6 && str[i])
	{
		j = -1;
		while (++j < 6)
			if (!ft_strncmp(str + i, tab[j], 2))
				cnt++;
		i++;
	}
	if (cnt != 6)
		return (2);
	while (str[i] && str[i] != '\n')
		i++;
	tmp = ft_strtrim(str + ++i, "\n ");
	if (check_double(tmp, '\n'))
		return (free(tmp), 1);
	return (free(tmp), 0);
}

int	check_cardinals(char **tab, t_args *args, int index)
{
	static int	count = 0;
	char		*extension;
	int			i;

	i = 0;
	while (tab[1][i])
	{
		if (!ft_isprint(tab[1][i]))
			return (ft_printf("Error path printable\n"), 1);
		i++;
	}
	if (tab[1])
	{
		extension = ft_strrchr(tab[1], '.');
		if (extension && ft_strcmp(extension, ".xpm") == 0)
		{
			if (count != 4)
				args->path[index] = ft_strdup(tab[1]);
			count++;
		}
		else
			return (ft_printf("Error: Invalid file extension\n"), 1);
	}
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
		if (ft_strlen(tab[i]) > 3 || ft_atoi(tab[i]) > 255
			|| ft_atoi(tab[i]) < 0)
			return (1);
		if (index == 4)
			args->floor[i] = ft_atoi(tab[i]);
		else
			args->celling[i] = ft_atoi(tab[i]);
		i++;
	}
	return (0);
}

int	check_args(char **file, t_args *args)
{
	int			i;
	int			index;
	char		**tmp;
	static char	*tab[6] = {"NO", "SO", "WE", "EA", "F", "C"};

	i = -1;
	while (++i < 6)
	{
		if (check_double(file[i], ','))
			return (1);
		tmp = ft_split(file[i], " ,");
		if (!tmp)
			return (free_tab(tmp), free_args(args), printf("Error\n"), 1);
		index = in_tab(tmp[0], tab);
		if (index == -1)
			return (printf("Error Cards\n"), free_tab(tmp), free_args(args), 1);
		if (index < 4 && (len_tab(tmp) != 2 || check_cardinals(tmp, args,
					index)))
			return (printf("Error cards\n"), free_tab(tmp), free_args(args), 1);
		else if (index >= 4 && (len_tab(tmp) != 4 || store_rgb(tmp, args,
					index)))
			return (printf("Error rgb\n"), free_tab(tmp), free_args(args), 2);
		free_tab(tmp);
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
	if (check_empty(str))
		return (free(str), printf("Error parsing\n"), 2);
	map->file = ft_split(str, "\n");
	free(str);
	if (!map->file)
		return (1);
	if (check_args(map->file, args))
		return (free_tab(map->file), 2);
	if (check_map(map->file, args, map))
		return (5);
	return (0);
}
