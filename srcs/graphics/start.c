#include "cub3d.h"

int	handle_key(int keycode, void *cub)
{
	if (keycode == 65307)
		exit_cub(cub, NULL, EXIT_SUCCESS);
	return (1);
}

int	render_cub(void *cub)
{
	if (cub)
		return (1);
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
	mlx_key_hook(cub->win_ptr, &handle_key, cub);
	mlx_loop(cub->mlx_ptr);
}
