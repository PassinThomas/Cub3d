/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:01:43 by akasekai          #+#    #+#             */
/*   Updated: 2024/12/02 13:51:18 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "define.h"
#include "typedef.h"

int			init_args(int fd, t_args *args, t_map *map);
int			check_newline(char *str);
int			check_map(char **file, t_args *args, t_map *map);
void		print_tab(char **tab);
int			check_all(char **tab, int i, int j, int err);

#endif