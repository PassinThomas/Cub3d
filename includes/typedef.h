/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:45:34 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/02 18:20:43 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_pos
{
	int		x;
	int		y;
	char	face;
}			t_pos;

typedef struct s_map
{
	char	**tab;
	int		height;
	t_pos	player;
	t_pos	exit;
	void	*mlx;
	void	*win;
}			t_map;

typedef struct s_args
{
	char	*path[4];
	int		floor[3];
	int		celling[3];
}			t_args;

#endif