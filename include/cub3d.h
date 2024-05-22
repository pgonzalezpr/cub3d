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
# define _USE_MATH_DEFINES

/*==========================HEADER FILES============================*/

# include "libft.h"
# include "../MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <string.h>

/*==========================STRING CONSTANTS============================*/

# define ARGC_ERR "Invalid number of arguments\n"
# define FORMAT_ERR "Invalid file\n"
# define MALLOC_ERR "Memory allocation error\n"
# define FILE_FORMAT ".cub"
# define WIN_ERR "Error opening window\n"
# define TXT_ERR "Error opening texture\n"

/*==========================NUMERIC CONSTANTS============================*/

# define W_WIDTH 1280
# define W_HEIGHT 720
# define TILE_SIZE 40
# define PI 3.14159265358979323846
# define FOV 60
# define MOV_SPEED 4
# define ROT_SPEED 0.07
# define TXT_ARR_SIZE 4
# define NO_TXT_IDX 0
# define SO_TXT_IDX 1
# define EA_TXT_IDX 2
# define WE_TXT_IDX 3

/*==========================EVENTS============================*/

# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define EXIT_EVENT 17

/*==========================KEY CODES LINUX============================*/

# define ESC_KEY_CODE 65307
# define W_KEY_CODE 119
# define A_KEY_CODE 97
# define S_KEY_CODE 115
# define D_KEY_CODE 100
# define LEFT_KEY_CODE 65361
# define RIGHT_KEY_CODE 65363

/*==========================KEY CODES MAC============================*/

/*
# define PRESS_MASK 0
# define RELEASE_MASK 0
# define EXIT_MASK 0
# define ESC_KEY_CODE 53
# define W_KEY_CODE 13
# define A_KEY_CODE 0
# define S_KEY_CODE 1
# define D_KEY_CODE 2
# define LEFT_KEY_CODE 123
# define RIGHT_KEY_CODE 124
*/

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
	int			x;
	int			y;
}				t_point;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			color;
}				t_color;

typedef struct s_move
{
	int			forw;
	int			backw;
	int			right;
	int			left;
	int			rot_right;
	int			rot_left;
}				t_move;

typedef struct s_player
{
	t_move		moves;
	t_point		pos_pix;
	double		angle;
	double		fov;
}				t_player;

typedef struct s_paths
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
}				t_paths;

typedef struct s_textures
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
}				t_textures;

typedef struct s_ray
{
	double		angle;
	double		distance;
	int			index;
	int			is_horz;
	int			x_horz;
	int			y_horz;
	int			x_vert;
	int			y_vert;
}				t_ray;

typedef struct s_map
{
	t_color		floor;
	t_color		ceiling;
	t_point		initial;
	char		**map_arr;
	int			height;
	char		ply_type;
}				t_map;

typedef struct s_cub
{
	t_paths		*paths;
	t_textures	*textures;
	t_map		*map;
	t_player	*player;
	t_ray		*ray;
	mlx_image_t	*img;
	mlx_t		*mlx_ptr;
}				t_cub;

/*=============================PARSING============================*/

void			parse_cub(char *filename, t_cub *cub);
//void			copy_file(int fd, t_parse *info);

/*=============================GRAPHICS============================*/

void			start_cub(t_cub *cub);
void			key_handler(mlx_key_data_t keydata, void *cub);
int				quit_cub(void *cub);
void			hook_cub(t_cub *cub);
void			raycast_cub(t_cub *cub);
void			render(t_cub *cub);
int				check_wall_hit(t_cub *cub, float x, float y);
int				check_limits(float angle, float *inter, float *step,
					int is_hrz);
int				check_circle(float angle, int is_hrz);
void			put_pixel(t_cub *cub, int pixel_x, int pixel_y,
					int pixel_color);
mlx_texture_t	*get_texture(t_cub *cub);
int				get_x_offset(mlx_texture_t *texture, t_cub *cub);
int				get_rgb_color(int r, int g, int b, int a);
int				reverse_bytes(int c);

/*=============================UTILS============================*/

void			*ft_malloc(size_t bytes, t_cub *cub);
int				ft_strrncmp(char *s1, char *s2, int n);
float			normalize_angle(float angle);
void			clean_cub(t_cub *cub);
void			print_cub(t_cub *cub);
void			exit_cub(t_cub *cub, char *msg, int status);
void			free_ptr(void *ptr);

#endif