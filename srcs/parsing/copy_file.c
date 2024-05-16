/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:27:03 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/16 15:35:47 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MAP_CHAR "10NSEW" 

int validate_single_map(char *content) 
{
    int i;
    int in_map;

	i = 0;
	in_map = 0;
    while (content[i] != '\0')
	{
        while (content[i] != '\0' && 
               (ft_strncmp(&content[i], "NO", 2) == 0 || 
                ft_strncmp(&content[i], "SO", 2) == 0 ||
                ft_strncmp(&content[i], "EA", 2) == 0 ||
                ft_strncmp(&content[i], "WE", 2) == 0 ||
                ft_strncmp(&content[i], "F ", 2) == 0 || 
                ft_strncmp(&content[i], "C ", 2) == 0))
		{
            while (content[i] != '\0' && content[i] != '\n')
                i++;
            if (content[i] == '\n')
                i++;
        }
        if (ft_strchr(MAP_CHAR, content[i])) 
		{
            if (in_map) 
				return (1);
            in_map = 1;
            while (content[i] != '\0') 
			{
				if (content[i] == '\n' && content[i + 1] && content[i + 1] == '\n')
					break;
                if (!ft_strchr(MAP_CHAR, content[i]) && content[i] != ' ' &&
					content[i] != '\t' && content[i] != '\n')
                    break;
                i++;
            }
		}
		//HERE TO CHECK FOR OTHER RANDOM TEXT(INVALID_INFO.CUB)
        while (content[i] != '\0' && content[i] != '\n')
            i++;
        if (content[i] == '\n')
            i++;
    }
    return (0);
}

void	copy_file(int fd, t_parse *info, t_cub *cub)
{
	char	*tmp;
	
	info->map_line = ft_calloc(1, sizeof(char));
	tmp = get_next_line(fd);
	if (!tmp)
	{
		free(info->map_line);
		exit_cub(cub, FORMAT_ERR, EXIT_FAILURE);
	}
	while(tmp)
	{
		info->map_line = ft_strjoin1(info->map_line, tmp);
		free (tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	if (validate_single_map(info->map_line)) 
	{
        free(info->map_line);
        exit_cub(cub, "Invalid parameters\n", EXIT_FAILURE);
    }
	get_matrix(info, cub);
}
