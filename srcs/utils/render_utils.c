/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:02:12 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/22 18:02:13 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

int	get_rgb_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

int	get_x_offset(mlx_texture_t *texture, t_cub *cub)
{
	if (cub->ray->is_horz)
		return ((int)fmodf((cub->ray->x_horz * (texture->width / TILE_SIZE)),
				texture->width));
	return ((int)fmodf((cub->ray->y_vert * (texture->width / TILE_SIZE)),
			texture->width));
}

void	put_pixel(t_cub *cub, int pixel_x, int pixel_y, int pixel_color)
{
	if (pixel_x < 0)
		return ;
	else if (pixel_x >= W_WIDTH)
		return ;
	if (pixel_y < 0)
		return ;
	else if (pixel_y >= W_HEIGHT)
		return ;
	mlx_put_pixel(cub->img, pixel_x, pixel_y, pixel_color);
}

mlx_texture_t	*get_texture(t_cub *cub)
{
	cub->ray->angle = normalize_angle(cub->ray->angle);
	if (cub->ray->is_horz)
	{
		if (cub->ray->angle > 0 && cub->ray->angle < PI)
			return (cub->textures->so);
		return (cub->textures->no);
	}
	else
	{
		if (cub->ray->angle > PI / 2 && cub->ray->angle < 3 * PI / 2)
			return (cub->textures->we);
		return (cub->textures->ea);
	}
}
