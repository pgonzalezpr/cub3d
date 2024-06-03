/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:16:46 by adanylev          #+#    #+#             */
/*   Updated: 2024/06/03 14:00:39 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define PLAYER "WENS"

int	check_player(t_parse *info, t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (cub->map->map_arr[x])
	{
		y = 0;
		while (cub->map->map_arr[x][y])
		{
			if (ft_strchr(PLAYER, cub->map->map_arr[x][y]))
			{
				info->player++;
				if (info->player != 1)
					return (1);
				cub->map->ply_type = cub->map->map_arr[x][y];
				cub->map->initial.x = y;
				cub->map->initial.y = x;
			}
			y++;
		}
		x++;
	}
	if (info->player != 1)
		return (1);
	return (0);
}

int	check_walls(t_parse *info)
{
	int	x;
	int	y;

	x = 0;
	while (info->map_matrix[x])
	{
		y = 0;
		while (info->map_matrix[x][y])
		{
			if (info->map_matrix[x][y] == '0' || ft_strchr(PLAYER,
					info->map_matrix[x][y]))
			{
				if (info->map_matrix[x - 1][y] == ' ' || info->map_matrix[x
					- 1][y] == '\t' || info->map_matrix[x][y - 1] == ' '
					|| info->map_matrix[x][y - 1] == '\t' || info->map_matrix[x
					+ 1][y] == ' ' || info->map_matrix[x + 1][y] == '\t'
					|| info->map_matrix[x][y + 1] == ' '
					|| info->map_matrix[x][y + 1] == '\t')
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
