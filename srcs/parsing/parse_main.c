/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:15:02 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/15 15:15:27 by adanylev         ###   ########.fr       */
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
void	init(t_parse *info)
{
	info->map_line = NULL;
	info->player = 0;
	info->ea = 0;
	info->we = 0;
	info->so = 0;
	info->no = 0;
	info->c = 0;
	info->f = 0;
}

void	parse_cub(char *filename, t_cub *cub)
{
	t_parse	info;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_cub(cub, FORMAT_ERR, EXIT_FAILURE);
	init(&info);
	copy_file(fd, &info, cub);
	if (filename && cub)
		return ;
}
