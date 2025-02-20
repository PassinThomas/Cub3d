/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:02:39 by tpassin           #+#    #+#             */
/*   Updated: 2025/02/20 20:16:01 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	in_tab(char *str, char **tab)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strcmp(str, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	is_border(char **tab, int i, int j)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	if (i + 1 >= size || i <= 0 || j >= ft_strlen(tab[i]) || j <= 0)
		return (1);
	if ((j > ft_strlen(tab[i + 1]) || tab[i + 1][j] == '\0' || tab[i
			+ 1][j] == '\n' || tab[i + 1][j] == ' '))
		return (2);
	if ((j > ft_strlen(tab[i - 1]) || tab[i - 1][j] == '\0' || tab[i
			- 1][j] == '\n' || tab[i - 1][j] == ' '))
		return (3);
	if ((tab[i][j + 1] == '\0' || tab[i][j + 1] == '\n' || tab[i][j
			+ 1] == ' '))
		return (4);
	if ((tab[i][j - 1] == '\0' || tab[i][j - 1] == '\n' || tab[i][j
			- 1] == ' '))
		return (5);
	return (0);
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

int	is_cub(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size < 4)
		return (0);
	if (ft_strcmp(".cub", &str[size - 4]))
		return (0);
	return (1);
}

// void	print_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 		printf("%s\n", tab[i++]);
// }

// void	print_struct(t_args *args)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("args->path[%i] = %s\n", i, args->path[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 3)
// 	{
// 		printf("floor[%i] == %i\n", i, args->floor[i]);
// 		printf("celling[%i] == %i\n", i, args->celling[i]);
// 		i++;
// 	}
// }

void	free_args(t_args *args)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (args->path[i])
			free(args->path[i]);
		i++;
	}
}
