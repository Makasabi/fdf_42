/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:19:04 by mrony             #+#    #+#             */
/*   Updated: 2023/05/19 16:11:07 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "fdf.h"

typedef struct s_map
{
	int		height;
	int		red;
	int		green;
	int		blue;
	int		r_reset;
	int		g_reset;
	int		b_reset;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	red;
	int	green;
	int	blue;
}	t_point;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_build
{
	char	**split;
	int		width;
	int		length;
	int		height;
	int		red;
	int		green;
	int		blue;
	char	*base;
	char	*map_name;
	int		map_min;
	int		map_max;
	t_list	*maplist;
	t_map	**map;
}	t_build;

typedef enum e_proj
{
	ISOMETRIC,
	PARALLEL,
	SIDE,
}	t_proj;

typedef struct s_fdf
{
	t_map		**map;
	t_build		*build;
	t_proj		proj;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			map_width;
	int			map_height;
	int			map_min;
	int			map_max;
	int			zoom;
	int			trans_x;
	int			trans_y;
	float		rot_x;
	float		rot_y;
	float		rot_z;
	float		z_index;
	int			colors[12];
}				t_fdf;

typedef struct s_bresenham
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		inc_x;
	int		inc_y;
	int		slope;
	int		error;
	int		error_inc;
}	t_bres;

#endif