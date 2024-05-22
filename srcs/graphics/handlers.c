/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:59:04 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/15 11:59:05 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press(mlx_key_data_t keydata, void *cub)
{
	t_cub	*cub_p;

	cub_p = (t_cub *)cub;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		exit_cub(cub_p, NULL, EXIT_SUCCESS);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		cub_p->player->moves.left = 1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		cub_p->player->moves.right = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		cub_p->player->moves.backw = 1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		cub_p->player->moves.forw = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		cub_p->player->moves.rot_left = 1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		cub_p->player->moves.rot_right = 1;
}

void	key_release(mlx_key_data_t keydata, void *cub)
{
	t_cub	*cub_p;

	cub_p = (t_cub *)cub;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		cub_p->player->moves.left = 0;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		cub_p->player->moves.right = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		cub_p->player->moves.backw = 0;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		cub_p->player->moves.forw = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		cub_p->player->moves.rot_left = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		cub_p->player->moves.rot_right = 0;
}

void	key_handler(mlx_key_data_t keydata, void *cub)
{
	key_press(keydata, cub);
	key_release(keydata, cub);
}

int	quit_cub(void *cub)
{
	exit_cub(cub, NULL, EXIT_SUCCESS);
	return (1);
}
