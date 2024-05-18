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
	mlx_destroy_image(cub_p->mlx_ptr, cub_p->img->ptr);
	cub_p->img->ptr = mlx_new_image(cub_p->mlx_ptr, W_WIDTH, W_HEIGHT);
	cub_p->img->width = W_WIDTH;
	cub_p->img->height = W_HEIGHT;
	cub_p->img->pixels = mlx_get_data_addr(cub_p->img->ptr,
			&cub_p->img->bits_per_pixel, &cub_p->img->size_line,
			&cub_p->img->endian);
	if (!cub_p->img->pixels)
		exit_cub(cub, WIN_ERR, EXIT_FAILURE);
	hook_cub(cub);
	raycast_cub(cub);
	mlx_put_image_to_window(cub_p->mlx_ptr, cub_p->win_ptr,
		cub_p->img->ptr, 0, 0);
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

void	open_texture(t_cub *cub, int idx, char *path)
{
	t_image	*textures;
	int		w;
	int		h;

	textures = cub->textures;
	textures[idx].ptr = mlx_xpm_file_to_image(cub->mlx_ptr, path, &w, &h);
	if (!textures[idx].ptr)
		exit_cub(cub, TXT_ERR, EXIT_FAILURE);
	textures[idx].width = w;
	textures[idx].height = h;
	textures[idx].pixels = mlx_get_data_addr(textures[idx].ptr,
			&textures[idx].bits_per_pixel, &textures[idx].size_line,
			&textures[idx].endian);
	if (!textures[idx].pixels)
		exit_cub(cub, TXT_ERR, EXIT_FAILURE);
}

void	init_textures(t_cub *cub)
{
	open_texture(cub, NO_TXT_IDX, cub->paths->no_path);
	open_texture(cub, SO_TXT_IDX, cub->paths->so_path);
	open_texture(cub, EA_TXT_IDX, cub->paths->ea_path);
	open_texture(cub, WE_TXT_IDX, cub->paths->we_path);
}

void	start_cub(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		exit_cub(cub, WIN_ERR, EXIT_FAILURE);
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, W_WIDTH, W_HEIGHT, "cub3d");
	cub->img->ptr = mlx_new_image(cub->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!cub->win_ptr || !cub->img->ptr)
		exit_cub(cub, WIN_ERR, EXIT_FAILURE);
	init_player(cub);
	init_textures(cub);
	mlx_loop_hook(cub->mlx_ptr, &render_cub, cub);
	mlx_hook(cub->win_ptr, KEY_PRESS_EVENT, 1L << 0, &key_press, cub);
	mlx_hook(cub->win_ptr, KEY_RELEASE_EVENT, 1L << 1, &key_release, cub);
	mlx_hook(cub->win_ptr, EXIT_EVENT, 1L << 17, &quit_cub, cub);
	mlx_loop(cub->mlx_ptr);
}
