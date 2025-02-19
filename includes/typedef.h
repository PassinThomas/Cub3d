/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:17:13 by tpassin           #+#    #+#             */
/*   Updated: 2025/01/29 17:07:21 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_vector2_d
{
	double		x;
	double		y;
}				t_vector2_d;

typedef struct s_pos
{
	int			x;
	int			y;
	char		face;
}				t_pos;

typedef struct s_args
{
	char		*path[4];
	int			floor[3];
	int			celling[3];
	int			north;
	int			south;
	int			east;
	int			west;
}				t_args;

typedef struct s_camera
{
	t_vector2_d	dir;
	t_vector2_d	plane;
	t_vector2_d	pos;
}				t_camera;

typedef struct s_ray
{
	t_vector2_d	raydir;
	t_vector2_d	sidedist;
	t_vector2_d	deltaDist;
	double		perp_walldist;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			side;
}				t_ray;

typedef struct
{
	int			player;
	int			height;
	int			width;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color;
	int			tex_x;
	int			tex_y;
	int			prev_x;
	int			scale;
	double		wall_x;
	double		step;
	double		tex_pos;
}				t_img;

typedef struct s_map
{
	char		**tab;
	char		**file;
	int			**map;
	int			height;
	int			width;
	int			y;
	double		margin;
	t_pos		pos;
	t_pos		exit;
	t_args		args;
	t_camera	camera;
	t_img		img;
	t_img		text[4];
	void		*mlx;
	void		*win;
	int			keyboard[256];
	int			fd;
	bool		left_pressed;
	bool		right_pressed;
}				t_map;

#endif