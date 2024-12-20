/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:05:14 by tpassin           #+#    #+#             */
/*   Updated: 2024/12/20 15:13:49 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector2_d dda(t_map *data, t_ray *ray)
{
  ray->ray_dir = ray->hit_point;
  ray->ori.x = data->player.pos_x;
  ray->ori.y = data->player.pos_y;
  t_vector2_f side_dist; // Origin point offset to the nearest int positon
  t_vector2_f delta_dist; // Length of the hyptenuse

  delta_dist.x = (ray->ray_dir.x == 0) ? 1e30 : fabs(1.0f / ray->ray_dir.x); // 1e30 is a large value
  delta_dist.y = (ray->ray_dir.x == 0) ? 1e30 : fabs(1.0f / ray->ray_dir.y);

  t_vector2_d step;
  if (ray->ray_dir.x < 0)
  {
    step.x = -1; // Calculating X step (depending on the direction)
    side_dist.x = (ray->ori.x - map.x) * delta_dist.x; // Calculating X gap to the nearest integer coordinate
  }
  else
  {
    step.x = 1;
    side_dist.x = (map.x + 1.0f - origin.x) * delta_dist.x;
  }

  if (dir.y < 0)
  {
    step.y = -1; // Calculating Y step (depending on the direction)
    side_dist.y = (origin.y - map.y) * delta_dist.y; // Calculating Y gap to the nearest integer coordinate
  }
  else
  {
    step.y = 1;
    side_dist.y = (map.y + 1.0f - origin.y) * delta_dist.y;
  }
  while (1)
  {
    if (side_dist.x < side_dist.y)
    {
        side_dist.x += delta_dist.x;
        map.x += step.x;
    }
    else
    {
        side_dist.y += delta_dist.y;
        map.y += step.y;
    }
  // Converting pixel coordinates to tab coordinates
    t_vector2_i cell = {map.x / CELL, map.y / CELL};
    if (cell.x < 0 || cell.x >= data->width)
      continue;
    if (cell.y < 0 || cell.y >= data->height)
      continue;
    if (data->map[cell.y][cell.x] == 1) // Is a wall
    {
      return (map);
    }
  }
}
