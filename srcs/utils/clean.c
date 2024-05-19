/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:00:03 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/15 12:00:04 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_image(t_cub *cub, t_image *img)
{
	if (!img)
		return ;
	if (cub->mlx_ptr && img->ptr)
		mlx_destroy_image(cub->mlx_ptr, img->ptr);
}

void	clean_images(t_cub *cub)
{
	free_image(cub, cub->img);
	free_ptr(cub->img);
	free_image(cub, &cub->textures[NO_TXT_IDX]);
	free_image(cub, &cub->textures[SO_TXT_IDX]);
	free_image(cub, &cub->textures[EA_TXT_IDX]);
	free_image(cub, &cub->textures[WE_TXT_IDX]);
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
	clean_images(cub);
	free_ptr(cub->ray);
	free_ptr(cub->player);
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
}
