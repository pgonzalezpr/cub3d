/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:59:22 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/15 11:59:25 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub *cub, int code)
{
	if (code == ROT_RIGHT_CODE)
		cub->player->angle = normalize_angle(cub->player->angle + ROT_SPEED);
	if (code == ROT_LEFT_CODE)
		cub->player->angle = normalize_angle(cub->player->angle - ROT_SPEED);
}

void	move_player(t_cub *cub, double x_delta, double y_delta)
{
	char	**arr;
	int		next_x;
	int		next_y;
	int		next_map_x;
	int		next_map_y;

	next_x = roundf(cub->player->pos_pix.x + x_delta);
	next_y = roundf(cub->player->pos_pix.y + y_delta);
	next_map_x = next_x / TILE_SIZE;
	next_map_y = next_y / TILE_SIZE;
	arr = cub->map->map_arr;
	if (arr[next_map_y][next_map_x] != '1'
		&& arr[next_map_y][cub->player->pos_pix.x / TILE_SIZE] != '1'
		&& arr[cub->player->pos_pix.y / TILE_SIZE][next_map_x] != '1')
	{
		cub->player->pos_pix.x = next_x;
		cub->player->pos_pix.y = next_y;
	}
}

void	get_deltas(t_cub *cub, int code, double *x_delta, double *y_delta)
{
	if (code == MOV_FORW_CODE)
	{
		*x_delta = cos(cub->player->angle) * MOV_SPEED;
		*y_delta = sin(cub->player->angle) * MOV_SPEED;
	}
	if (code == MOV_BACKW_CODE)
	{
		*x_delta = -cos(cub->player->angle) * MOV_SPEED;
		*y_delta = -sin(cub->player->angle) * MOV_SPEED;
	}
	if (code == MOV_LEFT_CODE)
	{
		*x_delta = sin(cub->player->angle) * MOV_SPEED;
		*y_delta = -cos(cub->player->angle) * MOV_SPEED;
	}
	if (code == MOV_RIGHT_CODE)
	{
		*x_delta = -sin(cub->player->angle) * MOV_SPEED;
		*y_delta = cos(cub->player->angle) * MOV_SPEED;
	}
}

void	hook_cub(t_cub *cub)
{
	double	x_delta;
	double	y_delta;

	x_delta = 0;
	y_delta = 0;
	if (cub->player->moves.rot_right)
		rotate_player(cub, ROT_RIGHT_CODE);
	if (cub->player->moves.rot_left)
		rotate_player(cub, ROT_LEFT_CODE);
	if (cub->player->moves.forw)
		get_deltas(cub, MOV_FORW_CODE, &x_delta, &y_delta);
	if (cub->player->moves.backw)
		get_deltas(cub, MOV_BACKW_CODE, &x_delta, &y_delta);
	if (cub->player->moves.left)
		get_deltas(cub, MOV_LEFT_CODE, &x_delta, &y_delta);
	if (cub->player->moves.right)
		get_deltas(cub, MOV_RIGHT_CODE, &x_delta, &y_delta);
	if (x_delta || y_delta)
		move_player(cub, x_delta, y_delta);
}
