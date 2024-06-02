/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:27:03 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/27 11:41:48 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n'))
		return (1);
	return (0);
}

int	accepted(char *content)
{
	if (ft_strncmp(content, "NO", 2) == 0 || ft_strncmp(content, "SO", 2) == 0
		|| ft_strncmp(content, "EA", 2) == 0 || ft_strncmp(content, "WE",
			2) == 0 || ft_strncmp(content, "F ", 2) == 0 || ft_strncmp(content,
			"C ", 2) == 0)
		return (1);
	return (0);
}

int	check_first_params(char *content, int *i, int *in_map)
{
	while (content[*i] && is_whitespace(content[*i]))
		*i += 1;
	while (content[*i] && accepted(&content[*i]))
	{
		while (content[*i] && content[*i] != '\n')
			*i += 1;
		if (content[*i] == '\n')
			*i += 1;
		if (*in_map)
			return (1);
	}
	if (!*in_map && content[*i] && !ft_strchr(MAP_CHAR, content[*i])
		&& !is_whitespace(content[*i]))
		return (1);
	return (0);
}

int	validate_single_map(char *content)
{
	int	i;
	int	in_map;

	i = 0;
	in_map = 0;
	while (content[i])
	{
		if (check_first_params(content, &i, &in_map))
			return (1);
		if (ft_strchr(MAP_CHAR, content[i]))
		{
			if (in_map)
				return (1);
			in_map = 1;
			while (content[i] && !(content[i] == '\n' && content[i + 1]
					&& content[i + 1] == '\n'))
			{
				if (!ft_strchr(MAP_CHAR, content[i])
					&& !is_whitespace(content[i]))
					return (1);
				i++;
			}	
		}
		if (content[i])
			i++;
	}
	return (!in_map);
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
	while (tmp)
	{
		info->map_line = ft_strjoin1(info->map_line, tmp);
		free(tmp);
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
