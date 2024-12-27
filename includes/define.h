/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:45:31 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/27 00:01:55 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "../libft/libft.h"
# include "../mlx/mlx/mlx.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// DATA
# define ERR "Map must be valid"
# define FOV 66
# define PI 3.1415926535
# define CELL 40
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define MOVE_SPEED 0.05f
# define ROT_SPEED 0.03f

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
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define MAGENTA 0x00FF00FF
# define ORANGE 0x00FFA500
# define PURPLE 0x008A2BE2
# define PINK 0x00FFC0CB
# define BROWN 0x00A52A2A
# define GREY 0x00808080

#endif