/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:15:02 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/13 13:06:54 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 *  Textures paths should go into cub->textures->xx_path
 * 	RGB color components should go into cub->map->floor/ceiling.r/g/b
 * 
 *  The map should be allocated with malloc and saved in into cub->map->map_arr.
 *  Store map dimensions in cub->map->heigth/width
 * 
 *  The player initial position has to be stored in cub->player->pos.x/y. 
 *  X and y are the horizontal and vertical dimensions, measured from 0 to 
 *  cub->map->width and cub->map->height, respectively. Store the player 
 *  initial orientation in cub->map->player->type. 
*/

void	parse_cub(char *filename, t_cub *cub)
{
	//copy_file(fd, &info);
	if (filename && cub)
		return ;
}
