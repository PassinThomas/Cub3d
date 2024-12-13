/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:51:02 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/10 14:07:28 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_right(char **tab, int i, int j)
{
	while (tab[i][j])
	{
		if (tab[i][j] == '1')
			return (1);
		if (tab[i][j] != '0' && tab[i][j] != '1')
			return (0);
		j++;
	}
	return (0);
}

int	check_left(char **tab, int i, int j)
{
	while (j >= 0)
	{
		if (tab[i][j] == '1')
			return (1);
		if (tab[i][j] != '0' && tab[i][j] != '1')
			return (0);
		j--;
	}
	return (0);
}

int	check_down(char **tab, int i, int j, int height)
{
	while (tab[i])
	{
		if (j >= ft_strlen(tab[i]))
			return (0);
		if (tab[i][j] == '1')
			return (1);
		if (tab[i][j] != '0' && tab[i][j] != '1')
			return (0);
		i++;
	}
	return (0);
}

int	check_up(char **tab, int i, int j)
{
	while (i >= 0 && tab[i - 1])
	{
		if (tab[i][j] == '1')
			return (1);
		if (tab[i][j] != '0' && tab[i][j] != '1')
			return (0);
		i--;
	}
	return (0);
}

int	check_all(char **tab, int i, int j, int height)
{
	int	err;

	err = 0;
	err += check_right(tab, i, j);
	err += check_left(tab, i, j);
	err += check_down(tab, i, j, height);
	err += check_up(tab, i, j);
	if (err != 4)
		return (1);
	return (0);
}
