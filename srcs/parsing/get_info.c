/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:34:57 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/16 15:28:08 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// MAKE THE FUNCTIONS RETURN A NUMBER AND THEN IN MAIN PARS FREE AND EXIT
//craete a function for error cases to free everuthing etc and check textures extensions and map

void	check_params(char **file, t_parse *info)
{
	int		x;
	int		y;

	x = 0;
	while (file[x])
	{
		y = 0;
		while (file[x][y] && file[x][y + 1])
		{
			if (file[x][y] == 'N' && file[x][y + 1] == 'O')
				info->no++;
			else if (file[x][y] == 'S' && file[x][y + 1] == 'O')
				info->so++;
			else if (file[x][y] == 'W' && file[x][y + 1] == 'E')
				info->we++;
			else if (file[x][y] == 'E' && file[x][y + 1] == 'A')
				info->ea++;
			else if (file[x][y] == 'F')
				info->f++;
			else if (file[x][y] == 'C')
				info->c++;
			y++;
		}
		x++;
	}
}

int	check_extentions(t_cub *cub)
{
	if (ft_strrncmp(cub->textures->no_path, ".xpm", 4) &&
		ft_strrncmp(cub->textures->no_path, ".png", 4))
		return (1);
	if (ft_strrncmp(cub->textures->so_path, ".xpm", 4) &&
		ft_strrncmp(cub->textures->so_path, ".png", 4))
		return (1);
	if (ft_strrncmp(cub->textures->we_path, ".xpm", 4) &&
		ft_strrncmp(cub->textures->we_path, ".png", 4))
		return (1);
	if (ft_strrncmp(cub->textures->ea_path, ".xpm", 4) &&
		ft_strrncmp(cub->textures->ea_path, ".png", 4))
		return (1);
	return (0);
}

int	validate_params(t_parse *info)
{
	if (info->c != 1 || info->f != 1 || info->ea != 1 || info->we != 1 ||
		info->so != 1 || info->no != 1)
		return (1);
	return (0);
}

int	get_textures(t_cub *cub, char **file)
{
	int		x;
	int		y;

	x = 0;
	while (file[x])
	{
		y = 0;
		while (file[x][y] && file[x][y + 1])
		{
			if (file[x][y] == 'N' && file[x][y + 1] == 'O')
				cub->textures->no_path = ft_strtrim(file[x], "NO \t");
			else if (file[x][y] == 'S' && file[x][y + 1] == 'O')
				cub->textures->so_path = ft_strtrim(file[x], "SO \t");
			else if (file[x][y] == 'W' && file[x][y + 1] == 'E') 
				cub->textures->we_path = ft_strtrim(file[x], "WE \t");
			else if (file[x][y] == 'E' && file[x][y + 1] == 'A') 
				cub->textures->ea_path = ft_strtrim(file[x], "EA \t");
			else if (file[x][y] == 'F' || file[x][y] == 'C')
			{
				if (get_colours(&file[x][y], cub))
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	get_matrix(t_parse *info, t_cub	*cub)
{
	char	**file;
	
	file = ft_split(info->map_line, '\n');
	free(info->map_line);
	if (!file)
		exit_cub(cub, FORMAT_ERR, EXIT_FAILURE);
	check_params(file, info);
	if (validate_params(info) || get_textures(cub, file) || check_extentions(cub))
	{
		free_matrix(file, 0);
		exit_cub(cub, "Invalid parameters\n", EXIT_FAILURE);
	}
}