/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:45:31 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/10 12:51:50 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "../libft/libft.h"
# include "../mlx/mlx/mlx.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>

# define ERR "Map must be valid"
# define FOV 66
# define PI 3.1415926535
# define CELL 40
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define WALL 1
# define FLOOR 0
# define MOVE_SPEED 0.2f

// KEY
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ESC 65307

// COLOR
# define SALMON 0x00FFA07A
# define RED 0x00FF0000

#endif