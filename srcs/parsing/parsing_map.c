/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:03:52 by tpassin           #+#    #+#             */
/*   Updated: 2025/02/20 20:16:32 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_col(t_map *map)
{
	int			i;
	int			j;
	static int	tmp[100] = {0};

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (!ft_strchr(" 01NSEW", map->tab[i][j]))
				return (1);
			tmp[ft_strchr(" 01NSEW", map->tab[i][j])[0] - 48]++;
			j++;
		}
		i++;
	}
	if (tmp['N' - 48] + tmp['W' - 48] + tmp['E' - 48] + tmp['S' - 48] != 1)
		return (2);
	return (0);
}

void	get_index(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (ft_strchr("NSEW", map->tab[i][j]))
			{
				map->pos.y = i;
				map->pos.x = j;
				map->pos.face = ft_strchr("NSEW", map->tab[i][j])[0];
				map->tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

int	check_wall(char **tab)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '0')
				if (is_border(tab, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	backtrack(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == '0')
			{
				if (check_wall(map->tab))
					return (1);
			}
			if (map->tab[i][j] == ' ' || map->tab[i][j] == '\t')
				map->tab[i][j] = '1';
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(char **file, t_args *args, t_map *map)
{
	int	i;

	map->tab = NULL;
	map->tab = file + 6;
	i = 0;
	while (map->tab[i])
	{
		if (map->width < ft_strlen(map->tab[i]))
			map->width = ft_strlen(map->tab[i]);
		i++;
	}
	map->height = i;
	if (check_col(map))
		return (ft_printf("Error check_col %i\n", 1));
	get_index(map);
	if (backtrack(map))
		return (free_args(args), ft_printf("Error backtrack\n"), free_tab(file),
			1);
	return (0);
}
