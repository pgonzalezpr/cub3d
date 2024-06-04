/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:00:03 by pedro-go          #+#    #+#             */
/*   Updated: 2024/06/04 16:22:59 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delete_texture(mlx_texture_t *texture)
{
	if (texture)
		mlx_delete_texture(texture);
}

void	clean_textures(t_cub *cub)
{
	delete_texture(cub->textures->no);
	delete_texture(cub->textures->so);
	delete_texture(cub->textures->ea);
	delete_texture(cub->textures->we);
	free_ptr(cub->textures);
}

void	free_map(t_map *map)
{
	int	row;

	if (!map)
		return ;
	row = 0;
	if (map->map_arr)
	{
		while (row < map->height)
		{
			free_ptr(map->map_arr[row]);
			row++;
		}
	}
	free_ptr(map->map_arr);
	free_ptr(map);
}

void	free_paths(t_paths *paths)
{
	if (!paths)
		return ;
	free_ptr(paths->no_path);
	free_ptr(paths->so_path);
	free_ptr(paths->ea_path);
	free_ptr(paths->we_path);
	free_ptr(paths);
}

void	clean_cub(t_cub *cub)
{
	free_paths(cub->paths);
	free_map(cub->map);
	free_ptr(cub->ray);
	free_ptr(cub->player);
	clean_textures(cub);
	if (cub->mlx_ptr && cub->img)
		mlx_delete_image(cub->mlx_ptr, cub->img);
	if (cub->mlx_ptr)
		mlx_close_window(cub->mlx_ptr);
}
