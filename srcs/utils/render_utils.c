#include "cub3d.h"

int	get_x_offset(t_image *texture, t_cub *cub)
{
	if (cub->ray->is_horz)
		return ((int)fmodf((cub->ray->x_horz * (texture->width / TILE_SIZE)),
        texture->width));
	return ((int)fmodf((cub->ray->y_vert * (texture->width / TILE_SIZE)),
        texture->width));
}

void	put_pixel(t_cub *cub, int pixel_x, int pixel_y, int pixel_color)
{
	t_image	*img;
	char	*pixel;
	int		pixel_index;

	img = cub->img;
	if (pixel_x < 0 || pixel_x >= img->width || pixel_y < 0
		|| pixel_y >= img->height)
		return ;
	pixel_index = (pixel_y * img->size_line) + (pixel_x * (img->bits_per_pixel
				/ 8));
	pixel = img->pixels + pixel_index;
	if (img->endian == 1)
	{
		pixel[0] = (pixel_color >> 24) & 0xFF;
		pixel[1] = (pixel_color >> 16) & 0xFF;
		pixel[2] = (pixel_color >> 8) & 0xFF;
		pixel[3] = pixel_color & 0xFF;
	}
	else
	{
		pixel[0] = pixel_color & 0xFF;
		pixel[1] = (pixel_color >> 8) & 0xFF;
		pixel[2] = (pixel_color >> 16) & 0xFF;
		pixel[3] = (pixel_color >> 24) & 0xFF;
	}
}

t_image	*get_texture(t_cub *cub)
{
	cub->ray->angle = normalize_angle(cub->ray->angle);
	if (cub->ray->is_horz)
	{
		if (cub->ray->angle > 0 && cub->ray->angle < PI)
			return (&cub->textures[SO_TXT_IDX]);
		return (&cub->textures[NO_TXT_IDX]);
	}
	else
	{
		if (cub->ray->angle > PI / 2 && cub->ray->angle < 3 * PI / 2)
			return (&cub->textures[EA_TXT_IDX]);
		return (&cub->textures[WE_TXT_IDX]);
	}
}

int	reverse_bytes(int color)
{
	unsigned int    bytes;

	bytes = 0;
	bytes = 0;
	bytes |= (color & 0xFF) << 24;
	bytes |= (color & 0xFF00) << 8;
	bytes |= (color & 0xFF0000) >> 8;
	bytes |= (color & 0xFF000000) >> 24;
	return (bytes);
}
