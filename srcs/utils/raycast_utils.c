/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:02:05 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/22 18:02:06 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_circle(float angle, int is_hrz)
{
	if (is_hrz && angle > (PI / 2) && angle < (3 * PI) / 2)
		return (1);
	if (!is_hrz && angle > 0 && angle < PI)
		return (1);
	return (0);
}

float	normalize_angle(float angle)
{
	if (angle < 0)
		return (angle + 2 * PI);
	else if (angle > 2 * PI)
		return (angle - 2 * PI);
	return (angle);
}

int	check_limits(float angle, float *inter, float *step, int is_hrz)
{
	if (is_hrz)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	check_wall_hit(t_cub *cub, float x, float y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (1);
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y >= cub->map->height
		|| map_x >= (int)ft_strlen(cub->map->map_arr[map_y]))
		return (1);
	return (cub->map->map_arr[map_y][map_x] == '1');
}
