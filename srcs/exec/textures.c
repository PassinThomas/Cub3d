/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:40:36 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/27 18:57:33 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_text(t_map *map, t_img *text, char *path)
{
	text->img = mlx_xpm_file_to_image(map->mlx, path, &text->width,
			&text->height);
	if (text->img == NULL)
		return (1);
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_length, &text->endian);
	if (text->addr == NULL)
		return (1);
	return (0);
}

int	init_data(t_map *map)
{
	if (load_text(map, &map->text[0], map->args.path[0]))
		return (1);
	if (load_text(map, &map->text[1], map->args.path[1]))
		return (1);
	if (load_text(map, &map->text[2], map->args.path[2]))
		return (1);
	if (load_text(map, &map->text[3], map->args.path[3]))
		return (1);
	return (0);
}
