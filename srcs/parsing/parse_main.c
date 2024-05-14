/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:15:02 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/14 16:17:08 by annadanylev      ###   ########.fr       */
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
 *  The player initial position has to be stored in cub->map->initial.x/y. 
 *  X and y are the horizontal and vertical dimensions, measured from 0 to 
 *  cub->map->width and cub->map->height, respectively. Store the player 
 *  initial orientation in cub->map->ply_type. 
*/
void	init(t_parse *info, t_cub *cub)
{
	(void)cub;
	info->map_line = NULL;
	info->player = 0;
}

void	parse_cub(char *filename, t_cub *cub)
{
	t_parse	info;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_cub(cub, FORMAT_ERR, EXIT_FAILURE);
	init(&info, cub);
	copy_file(fd, &info);
	if (filename && cub)
		return ;
}
