/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:35:35 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/13 12:00:20 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_error(char *msg, t_parse *info)
{
	(void)info;
	//free info
	write(2, msg, ft_strlen(msg));
	exit(1);
}