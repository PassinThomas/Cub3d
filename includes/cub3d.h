/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:01:43 by akasekai          #+#    #+#             */
/*   Updated: 2025/02/19 15:33:23 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "typedef.h"

int		init_args(int fd, t_args *args, t_map *map);
int		check_newline(char *str);
int		check_map(char **file, t_args *args, t_map *map);
int		key_press(int keycode, t_map *map);
int		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		key_release(int keycode, t_map *map);
int		**init_map(t_map *map);
int		init_data(t_map *map);
int		get_texture_color(t_img *text, int x, int y);
void	print_struct(t_args *args);
void	render(t_map *map);
void	print_tab(char **tab);
void	init_pos_player(t_map *map);
void	calcul_ray(t_map *map, t_ray *ray, int x);
void	calcul_step(t_ray *ray, t_map *map);
void	dda(t_map *map, t_ray *ray);
void	draw_vert_line(t_img *img, int x, t_ray ray, t_map *map);
void	free_tab(char **tab);
void	free_all(t_map *map);
void	handle_movement(t_map *map);
void	rotate_left(t_map *map);
void	rotate_right(t_map *map);
void	ft_close_window(t_map *map);
void	start_game(t_map *map);
void	draw_floor_ceiling(t_img *img, t_map *map);
void	draw_minimap(t_map *map);
void	free_text(t_map *map);
void	free_args(t_args *args);
int		is_border(char **tab, int i, int j);
int		is_cub(char *str);
int		in_tab(char *str, char **tab);

#endif