/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:10:29 by mrony             #+#    #+#             */
/*   Updated: 2023/05/20 18:35:47 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdint.h>
# include <string.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <limits.h>
# include <stddef.h>
# include "fdf_structs.h"
# include "fdf_errors.h"
# include "fdf_colors.h"

/// WINDOWS ///

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 1000

// FUNCTIONS //

// read ///
int		ft_map_width(char *line);
int		ft_read_map(char *str, t_build *build);

// check //
void	ft_clean_line(t_list *maplist);
int		ft_line_check(char *line);
int		ft_check_map(t_build *build);

// parsing //
void	ft_map_parsing(t_build *build);

// mlx //
void	ft_mlx(t_build *build);

// mlx_hooks //
int		ft_handle_keypress(int keysym, t_fdf *fdf);
int		ft_handle_destroy_window(t_fdf *fdf);
int		ft_handle_mouse(int button, int x, int y, t_fdf *fdf);
int		ft_handle_no_event(void *data);

// // rendering //
int		ft_render(t_fdf *fdf);
void	img_pix_put(t_fdf *img, int x, int y, int color);
void	ft_restart(t_fdf *fdf, t_proj proj);

// Menu //
void	ft_menu_1(t_fdf *fdf);

// projection //

t_point	ft_rotate_z(t_fdf *fdf, t_point point);
t_point	ft_rotate_x(t_fdf *fdf, t_point point);
t_point	ft_rotate_y(t_fdf *fdf, t_point point);
t_point	ft_proj(t_fdf *fdf, t_point point);

// bresenham //
void	ft_bresen(t_fdf *fdf, t_point start, t_point end);

// Colors //
int		ft_encode_rgb(int red, int green, int blue);
t_color	ft_decode_color(int color);
int		ft_gradient(t_bres *bres, t_point *start, t_point *end);
float	ft_percent(int current, int start, int end);
void	ft_reset_colors(t_fdf *fdf, t_map **map);
void	ft_color_preset(t_fdf *fdf, t_map **map, \
	t_color start_c, t_color finish_c);
void	ft_color_array(t_fdf *fdf);
void	ft_color_lgbt(t_fdf *fdf, t_map **map);
t_color	ft_choose_color(t_fdf *fdf, t_color color, int y);

// utils //
void	ft_free_split(char **split, int size);
int		ft_is_char_here(char *str, char c);
int		ft_sgn(int nb);
void	ft_end_prog(t_map **map, int height, char *map_name);
float	ft_z_index(t_fdf *fdf, t_map **map);

// errors //
void	ft_exit_fail_split(char **split, char **split_color, t_build *build);
void	ft_exit_fail_read(char *line, t_list *maplist);
void	ft_exit_fail_fdfinit(t_build *build, char *str);
void	ft_exit_fail_winptr(t_build *build, t_fdf *fdf, char *str);

// Initialization //
void	ft_init_build(t_build *build, char *str);
t_map	**ft_create_map(t_build *build);
t_fdf	ft_fdf_init(t_fdf fdf, t_build *build);
void	ft_bres_data_init(t_bres *bres, t_point *start, t_point *end);
t_point	ft_init_p(t_map **map, int x, int y);

#endif