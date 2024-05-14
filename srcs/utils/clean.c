#include "cub3d.h"

void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	clean_cub(t_cub *cub)
{
	free_ptr(cub->textures);
	free_ptr(cub->map);
	free_ptr(cub->player);
}
