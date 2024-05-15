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

int	render_cub(void *cub)
{
	t_cub	*cub_p;

	cub_p = (t_cub *)cub;
	mlx_destroy_image(cub_p->mlx_ptr, cub_p->img);
	cub_p->img = mlx_new_image(cub_p->mlx_ptr, W_WIDTH, W_HEIGHT);
	hook_cub(cub);
	//raycast();
	mlx_put_image_to_window(cub_p->mlx_ptr, cub_p->win_ptr, cub_p->img, 0, 0);
	return (1);
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
	int	w;
	int	h;

	cub->textures->no = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->no_path, &w, &h);
	cub->textures->so = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->so_path, &w, &h);
	cub->textures->we = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->we_path, &w, &h);
	cub->textures->ea = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->textures->ea_path, &w, &h);
	if (!cub->textures->no || !cub->textures->so || !cub->textures->we
		|| !cub->textures->ea)
		exit_cub(cub, TXT_ERR, EXIT_FAILURE);
}

void	start_cub(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		exit_cub(cub, WIN_ERR, EXIT_FAILURE);
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, W_WIDTH, W_HEIGHT, "cub3d");
	if (!cub->win_ptr)
		exit_cub(cub, WIN_ERR, EXIT_FAILURE);
	init_player(cub);
	init_textures(cub);
	mlx_loop_hook(cub->mlx_ptr, &render_cub, cub);
    mlx_hook(cub->win_ptr, KEY_PRESS_EVENT, PRESS_MASK, &key_press, cub);
    mlx_hook(cub->win_ptr, KEY_RELEASE_EVENT, RELEASE_MASK, &key_release, cub);
    mlx_hook(cub->win_ptr, EXIT_EVENT, EXIT_MASK, &quit_cub, cub);
	cub->img = mlx_new_image(cub->mlx_ptr, W_WIDTH, W_HEIGHT);
	mlx_loop(cub->mlx_ptr);
}
