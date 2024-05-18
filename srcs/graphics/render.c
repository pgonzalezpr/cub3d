#include "cub3d.h"

void	render_floor_and_ceiling(t_cub *cub, double upper_pixel,
		double bottom_pixel)
{
	if (cub && upper_pixel && bottom_pixel)
		return ;
}

void	render_wall(t_cub *cub, int upper_pixel, int bottom_pixel,
		double wall_height)
{
	double		x_offset;
	double		y_offset;
	double		factor;
	t_image		*texture;
	__uint32_t	*pixels;

	texture = get_texture(cub);
	pixels = (__uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_height;
	x_offset = get_x_offset(texture, cub);
	y_offset = (upper_pixel - (W_HEIGHT / 2) + (wall_height / 2)) * factor;
	if (y_offset < 0)
		y_offset = 0;
	while (upper_pixel < bottom_pixel)
	{
		put_pixel(cub, cub->ray->index, upper_pixel, pixels[(int)y_offset
			* texture->width + (int)x_offset]);
		y_offset += factor;
		upper_pixel++;
	}
}

void	render(t_cub *cub)
{
	double	wall_height;
	double	upper_pixel;
	double	bottom_pixel;

	cub->ray->distance *= cos(normalize_angle(cub->ray->angle
				- cub->player->angle));
	wall_height = (TILE_SIZE / cub->ray->distance) * ((W_WIDTH / 2)
			/ tan(cub->player->fov / 2));
	bottom_pixel = (W_HEIGHT / 2) + (wall_height / 2);
	upper_pixel = (W_HEIGHT / 2) - (wall_height / 2);
	if (upper_pixel < 0)
		upper_pixel = 0;
	if (bottom_pixel > W_HEIGHT)
		bottom_pixel = W_HEIGHT;
	render_wall(cub, upper_pixel, bottom_pixel, wall_height);
	//render_floor_and_ceiling(cub, upper_pixel, bottom_pixel);
}
