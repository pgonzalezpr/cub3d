/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:35:32 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/22 13:23:14 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_cub(t_cub *cub, char *msg, int status)
{
	if (cub)
		clean_cub(cub);
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(status);
}

void	init_cub(t_cub *cub)
{
	ft_memset(cub, 0, sizeof(t_cub));
	cub->paths = ft_malloc(sizeof(t_paths), cub);
	cub->map = ft_malloc(sizeof(t_map), cub);
	cub->player = ft_malloc(sizeof(t_player), cub);
}

void	check_input(int argc, char **argv)
{
	size_t	len;
	char	*begin;

	if (argc != 2)
		exit_cub(NULL, ARGC_ERR, EXIT_FAILURE);
	len = ft_strlen(FILE_FORMAT);
	begin = ft_strchr(argv[1], '.');
	if (!begin || ft_strlen(begin) != len
		|| ft_strncmp(begin, FILE_FORMAT, len))
		exit_cub(NULL, FORMAT_ERR, EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	check_input(argc, argv);
	init_cub(&cub);
	parse_cub(argv[1], &cub);
	print_cub(&cub);
	exit_cub(&cub, NULL, EXIT_SUCCESS);
}
