/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:35:32 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/13 12:00:54 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parse	info;
	
    if (argc && argv)
	    printf("Hello cub3d\n");
	info = parsing_all(argc, argv);
}
