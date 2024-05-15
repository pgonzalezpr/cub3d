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

# include "cub3d.h"

int	key_press(int keycode, void *cub)
{
    t_cub   *cub_p;

    cub_p = (t_cub *) cub;
	if (keycode == ESC_KEY_CODE)
		exit_cub(cub, NULL, EXIT_SUCCESS);
    if (keycode == W_KEY_CODE)
        cub_p->player->moves.forw = 1;
    if (keycode == A_KEY_CODE)
        cub_p->player->moves.left = 1;
    if (keycode == S_KEY_CODE)
        cub_p->player->moves.backw = 1;
    if (keycode == D_KEY_CODE)
        cub_p->player->moves.right = 1;
    if (keycode == LEFT_KEY_CODE)
        cub_p->player->moves.rot_left = 1;
    if (keycode == RIGHT_KEY_CODE)
        cub_p->player->moves.rot_right = 1;
    return (1);
}

int	key_release(int keycode, void *cub)
{
    t_cub   *cub_p;

    cub_p = (t_cub *) cub;
	if (keycode == ESC_KEY_CODE)
		exit_cub(cub, NULL, EXIT_SUCCESS);
    if (keycode == W_KEY_CODE)
        cub_p->player->moves.forw = 0;
    if (keycode == A_KEY_CODE)
        cub_p->player->moves.left = 0;
    if (keycode == S_KEY_CODE)
        cub_p->player->moves.backw = 0;
    if (keycode == D_KEY_CODE)
        cub_p->player->moves.right = 0;
    if (keycode == LEFT_KEY_CODE)
        cub_p->player->moves.rot_left = 0;
    if (keycode == RIGHT_KEY_CODE)
        cub_p->player->moves.rot_right = 0;
    return (1);
}

int quit_cub(void *cub)
{
    exit_cub(cub, NULL, EXIT_SUCCESS);
    return (1);
}
