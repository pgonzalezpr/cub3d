#include "cub3d.h"

void	free_map(t_map *map)
{
	int	row;

	if (!map)
		return ;
	row = 0;
	if (map->map_arr)
	{
		while (row < map->height)
		{
			free_ptr(map->map_arr[row]);
			row++;
		}
	}
	free_ptr(map->map_arr);
	free_ptr(map);
}

void	free_paths(t_paths *paths)
{
	if (!paths)
		return ;
	free_ptr(paths->no_path);
	free_ptr(paths->so_path);
	free_ptr(paths->ea_path);
	free_ptr(paths->we_path);
	free_ptr(paths);
}

void	clean_cub(t_cub *cub)
{
	free_paths(cub->paths);
	free_map(cub->map);
	free_ptr(cub->player);
}