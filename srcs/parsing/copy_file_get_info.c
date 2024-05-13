/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file_get_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:27:03 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/13 14:44:30 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_matrix(t_parse *info)
{
	char	**file;
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	file = ft_split(info->map_line, '\n');
	if(!file)
		return (NULL);
	// here to extract textures and colors
	
	
}

void	copy_file(int fd, t_parse *info)
{
	char	*tmp;
	
	info->map_line = ft_calloc(1, sizeof(char));
	tmp = get_next_line(fd);
	if (!tmp)
		parsing_error("Error: empty file\n", info);
	while(tmp)
	{
		info->map_line = ft_strjoin(info->map_line, tmp);
		free (tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	get_matrix(info);
}
