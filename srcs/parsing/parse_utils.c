/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:56:26 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/25 13:31:42 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_copy(char *dst, char *src)
{
	int	i;

	i = 0;
	
	while (src[i])
	{
		dst[i + 1] = src[i];
		i++;
	}
}

int count_lines(char **str) 
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int	free_matrix(char **matrix, int err)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	if (matrix)
		free(matrix);
	if (err)
		return (1);
	return (0);
}

char	*ft_strjoin_copy(char *join, char *s1, char *s2)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (i < len1 + len2)
	{
		if (i < len1)
			join[i] = s1[i];
		else
			join[i] = s2[i - len1];
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*join;
	int		len1;
	int		len2;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	join = ft_strjoin_copy(join, s1, s2);
	free(s1);
	return (join);
}
