/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file_get_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:27:03 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/14 17:00:54 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_matrix(t_parse *info)
{
	char	**file;
	int		x;
	int		y;

	file = ft_split(info->map_line, '\n');
	if (!file)
		return (NULL);
	while (file[x])
	{
		while (file[x][y] && file[x][y + 1])
		{
			if (file[x][y] == 'N' && file[x][y + 1] == 'O')
				ft_strtrim(file[x], "NO \t");
				//continue with extraction
		}
	// here to extract textures and colors
	
	
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
		info->map_line = ft_strjoin(info->map_line, tmp);
		free (tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	get_matrix(info);
}
