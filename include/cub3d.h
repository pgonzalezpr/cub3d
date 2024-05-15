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
# include "mlx.h"
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
# define ROT_SPEED 0.05

/*==========================EVENTS============================*/

# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define EXIT_EVENT 17

/*
==========================KEY CODES LINUX============================

# define PRESS_MASK 1L<<0
# define RELEASE_MASK 1L<<1
# define EXIT_MASK 1L<<17
# define ESC_KEY_CODE 65307
# define W_KEY_CODE 119
# define A_KEY_CODE 97
# define S_KEY_CODE 115
# define D_KEY_CODE 100
# define LEFT_KEY_CODE 65361
# define RIGHT_KEY_CODE 65363

*/

/*==========================KEY CODES MAC============================*/

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
	t_point		initial;
	char		**map_arr;
	int			width;
	int			height;
	char		ply_type;
}				t_map;

typedef struct s_cub
{
	t_textures	*textures;
	t_map		*map;
	t_player	*player;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
}				t_cub;

/*=============================PARSING============================*/

void			parse_cub(char *filename, t_cub *cub);
//void			copy_file(int fd, t_parse *info);

/*=============================GRAPHICS============================*/

void			start_cub(t_cub *cub);
int				key_press(int keycode, void *cub);
int				key_release(int keycode, void *cub);
int				quit_cub(void *cub);
void			hook_cub(t_cub *cub);

/*=============================UTILS============================*/

void			*ft_malloc(size_t bytes, t_cub *cub);
int				ft_strrncmp(char *s1, char *s2, int n);
void			clean_cub(t_cub *cub);
void			print_cub(t_cub *cub);
void			exit_cub(t_cub *cub, char *msg, int status);

#endif