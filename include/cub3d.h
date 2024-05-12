/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:53 by pedro-go          #+#    #+#             */
/*   Updated: 2024/05/12 19:00:37 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <string.h>

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;


typedef struct s_parse
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			player;
	t_point		wall;
	t_point		person;
}				t_parse;


#endif
