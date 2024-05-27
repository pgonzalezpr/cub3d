/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:53 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/24 12:13:37 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define _USE_MATH_DEFINES

/*==========================HEADER FILES============================*/

# include "../MLX42/MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <string.h>

/*==========================STRING CONSTANTS============================*/

# define ARGC_ERR "Invalid number of arguments\n"
# define FORMAT_ERR "Invalid file\n"
# define MALLOC_ERR "Memory allocation error\n"
# define FILE_FORMAT ".cub"
# define MAP_CHAR "10NSEW"
# define WIN_ERR "Error opening window\n"
# define TXT_ERR "Error opening texture\n"

/*==========================NUMERIC CONSTANTS============================*/

# define W_WIDTH 1920
# define W_HEIGHT 1080
# define TILE_SIZE 40
# define PI 3.14159265358979323846
# define FOV 60
# define MOV_SPEED 4
# define ROT_SPEED 0.07

/*==========================MOVEMENTS============================*/

# define MOV_FORW_CODE 1
# define MOV_BACKW_CODE 2
# define MOV_RIGHT_CODE 3
# define MOV_LEFT_CODE 4
# define ROT_RIGHT_CODE 5
# define ROT_LEFT_CODE 6

/*=============================STRUCTS============================*/

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				color;
}					t_color;

typedef struct s_move
{
	int				forw;
	int				backw;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
}					t_move;

typedef struct s_player
{
	t_move			moves;
	t_point			pos_pix;
	double			angle;
	double			fov;
}					t_player;

typedef struct s_paths
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
}					t_paths;

typedef struct s_textures
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
}					t_textures;

typedef struct s_ray
{
	double			angle;
	double			distance;
	int				index;
	int				is_horz;
	int				x_horz;
	int				y_horz;
	int				x_vert;
	int				y_vert;
}					t_ray;

typedef struct s_map
{
	t_color			floor;
	t_color			ceiling;
	t_point			initial;
	char			**map_arr;
	int				height;
	int				width;
	char			ply_type;
}					t_map;

typedef struct s_cub
{
	t_paths			*paths;
	t_textures		*textures;
	t_map			*map;
	t_player		*player;
	t_ray			*ray;
	mlx_image_t		*img;
	mlx_t			*mlx_ptr;
}					t_cub;

typedef struct s_parse
{
	char			*map_line;
	char			**map_matrix;
	int				player;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
}					t_parse;

/*=============================PARSING============================*/

void				parse_cub(char *filename, t_cub *cub);
void				copy_file(int fd, t_parse *info, t_cub *cub);
void				init(t_parse *info);
void				get_matrix(t_parse *info, t_cub *cub);
int					get_colours(char *colour, t_cub *cub);
void				copy_error(t_parse *info, t_cub *cub);
int					free_matrix(char **matrix, int err);
char				*ft_strjoin1(char *s1, char *s2);
int					is_whitespace(char c);
void				get_map(t_parse *info, t_cub *cub, char **file);
int					count_lines(char **str);
int					check_player(t_parse *info, t_cub *cub);
int					check_walls(t_parse *info);
void				ft_copy(char *dst, char *src);

/*=============================GRAPHICS============================*/

void				start_cub(t_cub *cub);
void				key_handler(mlx_key_data_t keydata, void *cub);
int					quit_cub(void *cub);
void				hook_cub(t_cub *cub);
void				raycast_cub(t_cub *cub);
void				render(t_cub *cub);
int					check_wall_hit(t_cub *cub, float x, float y);
int					check_limits(float angle, float *inter, float *step,
						int is_hrz);
int					check_circle(float angle, int is_hrz);
void				put_pixel(t_cub *cub, int pixel_x, int pixel_y,
						int pixel_color);
mlx_texture_t		*get_texture(t_cub *cub);
int					get_x_offset(mlx_texture_t *texture, t_cub *cub);
int					get_rgb_color(int r, int g, int b, int a);
int					reverse_bytes(int c);

/*=============================UTILS============================*/

void				*ft_malloc(size_t bytes, t_cub *cub);
int					ft_strrncmp(char *s1, char *s2, int n);
float				normalize_angle(float angle);
void				clean_cub(t_cub *cub);
void				print_cub(t_cub *cub);
void				exit_cub(t_cub *cub, char *msg, int status);
void				free_ptr(void *ptr);

#endif