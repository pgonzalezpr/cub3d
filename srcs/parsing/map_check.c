/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:25:05 by annadanylev       #+#    #+#             */
/*   Updated: 2024/05/22 15:24:12 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_with_spaces(t_parse *info, t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < cub->map->height + 3)
	{
		info->map_matrix[x] = ft_malloc(sizeof(char) * (cub->map->width + 3),
				cub);
		info->map_matrix[x] = ft_memset(info->map_matrix[x], ' ',
				cub->map->width + 2);
		info->map_matrix[x][cub->map->width + 2] = '\0';
		x++;
	}
	x = 0;
	y = 0;
	while (++x < cub->map->height + 1)
	{
		ft_copy(info->map_matrix[x], cub->map->map_arr[y]);
		y++;
	}
}

int	find_longest_line(char **matrix)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	len = (int)ft_strlen(matrix[x]);
	while (matrix[x])
	{
		y = x + 1;
		if (matrix[y] && len < (int)ft_strlen(matrix[y]))
			len = (int)ft_strlen(matrix[y]);
		x++;
	}
	return (len);
}

void	create_buffer(t_parse *info, t_cub *cub)
{
	cub->map->height = count_lines(cub->map->map_arr);
	cub->map->width = find_longest_line(cub->map->map_arr);
	info->map_matrix = ft_malloc(sizeof(char *) * (cub->map->height + 3), cub);
	info->map_matrix[cub->map->height + 2] = NULL;
	fill_with_spaces(info, cub);
}

void	get_map(t_parse *info, t_cub *cub, char **file)
{
	int	x;
	int	y;

	x = 5;
	cub->map->map_arr = ft_malloc(((count_lines(file) - 6) + 1)
			* sizeof(char *), cub);
	while (file[x])
	{
		y = 0;
		while (file[x][y] && is_whitespace(file[x][y]))
			y++;
		if ('1' == file[x][y])
			break ;
		x++;
	}
	y = 0;
	while (y < count_lines(file) - 6 && file[x])
		cub->map->map_arr[y++] = ft_strdup(file[x++]);
	cub->map->map_arr[y] = NULL;
	free_matrix(file, 0);
	create_buffer(info, cub);
	if (check_player(info, cub) || check_walls(info))
		exit_cub(cub, "Invalid map\n", EXIT_FAILURE);
	free_matrix(info->map_matrix, 0);
}
