/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:25:05 by annadanylev       #+#    #+#             */
/*   Updated: 2024/05/20 17:24:31 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int count_lines(char **str) 
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    check_walls(t_cub *cub)
{

}

void    get_map(t_parse *info, t_cub *cub, char **file)
{
    int x;
    int y;
    
    x = 5;
    (void)info;
    cub->map->map_arr = ft_malloc(((count_lines(file) - 6) + 1) * sizeof(char *), cub);
    while (file[x])
    {
        y = 0;
        while (file[x][y] && is_whitespace(file[x][y]))
            y++;
        if ('1' == file[x][y])
            break;
        x++;
    }
    y = 0;
    while (y < count_lines(file) - 6 && file[x])
        cub->map->map_arr[y++] = ft_strdup(file[x++]);
    cub->map->map_arr[y] = NULL;
    free_matrix(file, 0);
}