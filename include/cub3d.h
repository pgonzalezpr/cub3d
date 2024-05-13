/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:53 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/13 13:03:47 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <string.h>
# include <fcntl.h>

/*=============================PARSING============================*/

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;


typedef struct s_parse
{
	char		*map_line;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			player;
	char		player_type;
	int			color_up;
	int			color_down;
	t_point		player_pos;
}				t_parse;

void	*ft_malloc(size_t bytes);
t_parse	parsing_all(int argc, char **argv);
int		ft_strrncmp(char *s1, char *s2, int n);
void	parsing_error(char *msg, t_parse *info);
void	copy_file(int fd, t_parse *info);

#endif
