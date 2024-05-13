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

/*==========================HEADER FILES============================*/

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <string.h>

/*==========================STRING CONSTANTS============================*/

# define ARGC_ERR "Invalid number of arguments\n"
# define FORMAT_ERR "Invalid file\n"
# define MALLOC_ERR "Memory allocation error\n"
# define FILE_FORMAT ".cub"

/*=============================STRUCTS============================*/

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_player
{
	t_point		pos;
	char		type;
}				t_player;

typedef struct s_textures
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	void		*no;
	void		*so;
	void		*we;
	void		*ea;
}				t_textures;

typedef struct s_map
{
	t_color		floor;
	t_color		ceiling;
	char		**map_arr;
	int			width;
	int			height;
}				t_map;

typedef struct s_cub
{
	t_textures	*textures;
	t_map		*map;
	t_player	*player;
	void		*mlx_ptr;
}				t_cub;

/*=============================PARSING============================*/

void			parse_cub(char *filename, t_cub *cub);
//void			copy_file(int fd, t_parse *info);

/*=============================UTILS============================*/

void			*ft_malloc(size_t bytes, t_cub *cub);
int				ft_strrncmp(char *s1, char *s2, int n);
void			clean_cub(t_cub *cub);
void			exit_cub(t_cub *cub, char *msg, int status);

#endif
