/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:45:34 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/20 15:08:31 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

enum			MoveDirection
{
	FORWARD = 1,
	BACKWARD = -1
};

typedef struct s_pos
{
	int			x;
	int			y;
	char		face;
}				t_pos;

typedef struct s_vector2_i
{
	int	x;
	int	y;
}	t_vector2_i;

typedef struct s_vector2_d
{
	double	x;
	double	y;
}	t_vector2_d;

typedef struct s_vector2_f
{
	float	x;
	float	y;
}	t_vector2_f;

typedef struct s_ray
{
	t_vector2_d	hit_point;
	t_vector2_d	cell;
	t_vector2_d	ori;
	t_vector2_d	ray_dir;
	double		len;
	int			side_hit;
	double		angle;
	double		perp_len;
}	t_ray;

typedef struct s_args
{
	char		*path[4];
	int			floor[3];
	int			celling[3];
}				t_args;

typedef struct s_player
{
	double		dir_x;
	double		dir_y;
	double		pos_x;
	double		pos_y;
	float		angle;
	float		speed;
	float		rot_speed;
	t_pos		pos;
}				t_player;

typedef struct s_map
{
	char		**tab;
	int			**map;
	int			height;
	int			width;
	t_pos		pos;
	t_pos		exit;
	t_args		args;
	t_player	player;
	t_vector2_d d;
	t_vector2_f f;
	t_vector2_i i;
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			keyboard[203];
	int			mouse_y;
	int			mouse_x;
}				t_map;
#endif