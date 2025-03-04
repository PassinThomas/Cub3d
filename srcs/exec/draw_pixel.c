/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:50 by tpassin           #+#    #+#             */
/*   Updated: 2025/03/04 13:57:27 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return (ft_printf("Error pixel put\n"), 1);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	get_texture_color(t_img *text, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= text->width || y < 0 || y >= text->height)
		return (0);
	dst = text->addr + (y * text->line_length + x * (text->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_floor_ceiling(t_img *img, t_map *map)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceiling_color;

	ceiling_color = rgb_to_int(map->args.celling[0], map->args.celling[1],
			map->args.celling[2]);
	floor_color = rgb_to_int(map->args.floor[0], map->args.floor[1],
			map->args.floor[2]);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(img, x, y, ceiling_color);
			else
				my_mlx_pixel_put(img, x, y, floor_color);
			x++;
		}
		y++;
	}
}
