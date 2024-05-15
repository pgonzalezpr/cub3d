/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:27:03 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/15 15:27:00 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	get_matrix(info, cub);
}
