/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:01:40 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/22 18:01:41 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_vert_hit_dist(t_cub *cub, float angle)
{
	float	x;
	float	y;
	float	step_x;
	float	step_y;
	int		extra_pixel;

	step_x = TILE_SIZE;
	step_y = TILE_SIZE * tan(angle);
	x = floor(cub->player->pos_pix.x / TILE_SIZE) * TILE_SIZE;
	extra_pixel = check_limits(angle, &x, &step_x, 0);
	y = cub->player->pos_pix.y + (x - cub->player->pos_pix.x) * tan(angle);
	if ((step_y < 0 && check_circle(angle, 0)) || (step_y > 0
			&& !check_circle(angle, 0)))
		step_y *= -1;
	while (!check_wall_hit(cub, x - extra_pixel, y))
	{
		x += step_x;
		y += step_y;
	}
	cub->ray->x_vert = x;
	cub->ray->y_vert = y;
	return (sqrt(pow(x - cub->player->pos_pix.x, 2) + pow(y
				- cub->player->pos_pix.y, 2)));
}

double	get_horz_hit_dist(t_cub *cub, float angle)
{
	float	x;
	float	y;
	float	step_x;
	float	step_y;
	int		extra_pixel;

	step_y = TILE_SIZE;
	step_x = TILE_SIZE / tan(cub->ray->angle);
	y = floor(cub->player->pos_pix.y / TILE_SIZE) * TILE_SIZE;
	extra_pixel = check_limits(angle, &y, &step_y, 1);
	x = cub->player->pos_pix.x + (y - cub->player->pos_pix.y) / tan(angle);
	if ((step_x > 0 && check_circle(angle, 1)) || (step_x < 0
			&& !check_circle(angle, 1)))
		step_x *= -1;
	while (!check_wall_hit(cub, x, y - extra_pixel))
	{
		x += step_x;
		y += step_y;
	}
	cub->ray->x_horz = x;
	cub->ray->y_horz = y;
	return (sqrt(pow(x - cub->player->pos_pix.x, 2) + pow(y
				- cub->player->pos_pix.y, 2)));
}

void	raycast_cub(t_cub *cub)
{
	double	horz_inter;
	double	vert_inter;

	cub->ray->index = 0;
	cub->ray->angle = cub->player->angle - (cub->player->fov / 2);
	while (cub->ray->index < W_WIDTH)
	{
		cub->ray->is_horz = 0;
		horz_inter = get_horz_hit_dist(cub, normalize_angle(cub->ray->angle));
		vert_inter = get_vert_hit_dist(cub, normalize_angle(cub->ray->angle));
		if (vert_inter <= horz_inter)
			cub->ray->distance = vert_inter;
		else
		{
			cub->ray->distance = horz_inter;
			cub->ray->is_horz = 1;
		}
		render(cub);
		cub->ray->index++;
		cub->ray->angle += (cub->player->fov / W_WIDTH);
	}
}
