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

void	init(t_parse *info)
{
	info->ea = NULL;
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->map = NULL;
	info->player = 0;
	info->player_type = 0;
	info->color_down = 0;
	info->color_up = 0;
	info->map_line = 0;
}

t_parse	parsing_all(int argc, char **argv)
{
	int		fd;
	t_parse	info;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || ft_strrncmp(argv[1], ".cub", 4) || fd < 0 || !argv[1])
		parsing_error("Error: incorrect input\n", &info);
	init(&info);
	copy_file(fd, &info);
	
	return (info);
}
