/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:46:33 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/16 15:31:17 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_nums(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}


void	fill_colours(char **tmp, t_cub *cub, char c)
{
	if (c == 'f')
	{
		cub->map->floor.r = ft_atoi(tmp[0]);
		cub->map->floor.g = ft_atoi(tmp[1]);
		cub->map->floor.b = ft_atoi(tmp[2]);
	}
	else if (c == 'c')
	{
		cub->map->ceiling.r = ft_atoi(tmp[0]);
		cub->map->ceiling.g = ft_atoi(tmp[1]);
		cub->map->ceiling.b = ft_atoi(tmp[2]);
	}
}

int	get_colours(char *colour, t_cub *cub)
{
	char	**tmp;
	char 	*trimmed;
	int		i;

	tmp = ft_split(&colour[1], ',');	
	i = -1;
	while (tmp[++i])
	{

		trimmed = ft_strtrim(tmp[i], " \t");
		if (check_nums(trimmed) || i > 2 || ft_strlen(trimmed) > 3 || 
			((ft_strlen(trimmed)) == 3 && (ft_strncmp("256", trimmed, 3) <= 0)))
		{
			printf("%s\n", tmp[i]);
			free(trimmed);
			return (free_matrix(tmp, 1));
		}
		free(trimmed);
	}
	if (colour[0] == 'F')
		fill_colours(tmp, cub, 'f');
	else if (colour[0] == 'C')
		fill_colours(tmp, cub, 'c');
	return (0);
}
