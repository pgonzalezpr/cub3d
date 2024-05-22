/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:56:26 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/22 14:35:51 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	*ft_malloc(size_t bytes, t_cub *cub)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
		exit_cub(cub, MALLOC_ERR, EXIT_FAILURE);
	ft_memset(ptr, 0, bytes);
	return (ptr);
}

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (n && s1[i] && s2[j])
	{
		if (s2[j] != s1[i])
			return (1);
		j--;
		i--;
		n--;
	}
	if (n)
		return (1);
	return (0);
}
