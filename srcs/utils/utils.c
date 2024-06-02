/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:56:26 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/25 13:28:57 by annadanylev      ###   ########.fr       */
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
