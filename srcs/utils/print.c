#include "cub3d.h"

void	print_map(t_map *map)
{
	int		r;
	char	*row;

	r = 0;
	while (r < map->height)
	{
		row = map->map_arr[r];
		write(STDOUT_FILENO, row, ft_strlen(row));
		r++;
	}
}

/**
 * Prints the parsed contents from the input file for debugging purposes
*/
void	print_cub(t_cub *cub)
{
	ft_dprintf(STDOUT_FILENO, "NO: %s\n", cub->textures->no_path);
	ft_dprintf(STDOUT_FILENO, "SO: %s\n", cub->textures->so_path);
	ft_dprintf(STDOUT_FILENO, "WE: %s\n", cub->textures->we_path);
	ft_dprintf(STDOUT_FILENO, "EA: %s\n", cub->textures->ea_path);
	write(STDOUT_FILENO, "\n", 1);
	ft_dprintf(STDOUT_FILENO, "Floor color -> R: %d, G: %d, B: %d\n",
		cub->map->floor.r, cub->map->floor.g, cub->map->floor.b);
	ft_dprintf(STDOUT_FILENO, "Ceiling color -> R: %d, G: %d, B: %d\n",
		cub->map->ceiling.r, cub->map->ceiling.g, cub->map->ceiling.b);
	write(STDOUT_FILENO, "\n", 1);
	print_map(cub->map);
	write(STDOUT_FILENO, "\n", 1);
	ft_dprintf(STDOUT_FILENO, "Player -> x: %d, y: %d, type: %c\n",
		cub->map->initial.x, cub->map->initial.y, cub->map->ply_type);
}
