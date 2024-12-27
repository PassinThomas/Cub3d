/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:02:39 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/27 19:41:42 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

void	print_struct(t_args *args)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		printf("args->path[%i] = %s\n", i, args->path[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("floor[%i] == %i\n", i, args->floor[i]);
		printf("celling[%i] == %i\n", i, args->celling[i]);
		i++;
	}
}
