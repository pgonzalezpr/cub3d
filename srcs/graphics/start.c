/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:59:44 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/15 11:59:46 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_cub(void *cub)
{
	t_cub	*cub_p;

	cub_p = (t_cub *)cub;
	mlx_delete_image(cub_p->mlx_ptr, cub_p->img);
	cub_p->img = mlx_new_image(cub_p->mlx_ptr, W_WIDTH, W_HEIGHT);
	hook_cub(cub);
	raycast_cub(cub);
	mlx_image_to_window(cub_p->mlx_ptr, cub_p->img, 0, 0);
}

void	init_player(t_cub *cub)
{
	if (cub->map->ply_type == 'N')
		cub->player->angle = (3 * PI) / 2;
	else if (cub->map->ply_type == 'S')
		cub->player->angle = PI / 2;
	else if (cub->map->ply_type == 'W')
		cub->player->angle = PI;
	else if (cub->map->ply_type == 'E')
		cub->player->angle = 0;
	cub->player->pos_pix.x = (cub->map->initial.x * TILE_SIZE) + TILE_SIZE / 2;
	cub->player->pos_pix.y = (cub->map->initial.y * TILE_SIZE) + TILE_SIZE / 2;
	cub->player->fov = (FOV * PI) / 180;
}

void	init_textures(t_cub *cub)
{
	cub->textures->no = mlx_load_png(cub->paths->no_path);
	cub->textures->so = mlx_load_png(cub->paths->so_path);
	cub->textures->ea = mlx_load_png(cub->paths->ea_path);
	cub->textures->we = mlx_load_png(cub->paths->we_path);
	if (!cub->textures->no || !cub->textures->so || !cub->textures->ea
		|| !cub->textures->we)
		exit_cub(cub, TXT_ERR, EXIT_FAILURE);
	cub->map->ceiling.color = get_rgb_color(cub->map->ceiling.r,
			cub->map->ceiling.g, cub->map->ceiling.b, 255);
	cub->map->floor.color = get_rgb_color(cub->map->floor.r,
			cub->map->floor.g, cub->map->floor.b, 255);
}

void	start_cub(t_cub *cub)
{
	cub->mlx_ptr = mlx_init(W_WIDTH, W_HEIGHT, "cub3d", 1);
	if (!cub->mlx_ptr)
		exit_cub(cub, WIN_ERR, EXIT_FAILURE);
	cub->img = mlx_new_image(cub->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!cub->img)
		exit_cub(cub, WIN_ERR, EXIT_FAILURE);
	init_player(cub);
	init_textures(cub);
	mlx_loop_hook(cub->mlx_ptr, &render_cub, cub);
	mlx_key_hook(cub->mlx_ptr, &key_handler, cub);
	mlx_loop(cub->mlx_ptr);
}
