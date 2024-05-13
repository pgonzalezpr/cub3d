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
	cub->textures = ft_malloc(sizeof(t_textures), cub);
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

void	dummy_data(t_cub *cub)
{
	cub->textures->no_path = ft_strdup("./textures/no_texture.png");
	cub->textures->so_path = ft_strdup("./textures/so_texture.png");
	cub->textures->we_path = ft_strdup("./textures/we_texture.png");
	cub->textures->ea_path = ft_strdup("./textures/ea_texture.png");
	cub->map->floor.r = 220;
	cub->map->floor.g = 100;
	cub->map->floor.b = 0;
	cub->map->ceiling.r = 225;
	cub->map->ceiling.g = 30;
	cub->map->ceiling.b = 0;
	cub->map->map_arr[0] = ft_strdup("1111111111111111111111111");
	cub->map->map_arr[1] = ft_strdup("1000000000000000000100001");
	cub->map->map_arr[2] = ft_strdup("1001000000000N00000000001");
	cub->map->map_arr[3] = ft_strdup("1001000000000000001000001");
	cub->map->map_arr[4] = ft_strdup("1001000000000000001000001");
	cub->map->map_arr[5] = ft_strdup("1001000000100000001000001");
	cub->map->map_arr[6] = ft_strdup("1001000000000000001000001");
	cub->map->map_arr[7] = ft_strdup("1001000000001000001000001");
	cub->map->map_arr[8] = ft_strdup("1111111111111111111111111");
	cub->map->height = 9;
	cub->map->width = 25;
	cub->player->pos.x = 13;
	cub->player->pos.y = 2;
	cub->player->type = 'N';
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	check_input(argc, argv);
	init_cub(&cub);
	//parse_cub(argv[1], &cub);
	dummy_data(&cub);
	exit_cub(&cub, NULL, EXIT_SUCCESS);
}
