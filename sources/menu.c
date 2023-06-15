/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:25:45 by mrony             #+#    #+#             */
/*   Updated: 2023/05/20 18:36:57 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_menu_3(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	*str;

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	str = ft_itoa(fdf->z_index);
	mlx_string_put(mlx, win, 260, 260, WHITE, str);
	free(str);
	mlx_string_put(mlx, win, 20, 280, WHITE, "Exit       : Esc");
	mlx_string_put(mlx, win, 20, 310, PINK_1,
		"** Views **               ** Colors **" );
	mlx_string_put(mlx, win, 20, 330, WHITE,
		"Isometric  : i            Change Color : q" );
	mlx_string_put(mlx, win, 20, 350, WHITE,
		"Parallel   : p            Reset Color  : e" );
	mlx_string_put(mlx, win, 20, 370, WHITE,
		"Side       : o            Flag Colors  : w" );
}

void	ft_menu_2(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	*str;

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 20, 110, WHITE, "Min Height :");
	mlx_string_put(mlx, win, 174, 110, WHITE, "Max Height :");
	str = ft_itoa(fdf->map_min);
	mlx_string_put(mlx, win, 100, 110, WHITE, str);
	free(str);
	str = ft_itoa(fdf->map_max);
	mlx_string_put(mlx, win, 260, 110, WHITE, str);
	free(str);
	mlx_string_put(mlx, win, 100, 140, PURPLE_1, "~~ CONTROLS ~~");
	mlx_string_put(mlx, win, 20, 160, WHITE, "Zoom +/-   : Scroll" );
	mlx_string_put(mlx, win, 20, 180, WHITE, "Rotate z   : z/a");
	mlx_string_put(mlx, win, 20, 200, WHITE, "Rotate x   : x/s");
	mlx_string_put(mlx, win, 20, 220, WHITE, "Rotate y   : c/d");
	mlx_string_put(mlx, win, 20, 240, WHITE,
		"Move       : Up - Down - Left - Right");
	mlx_string_put(mlx, win, 20, 260, WHITE, "Height +/- : h/l");
	mlx_string_put(mlx, win, 174, 260, WHITE, "Z index    :");
	ft_menu_3(fdf);
}

void	ft_menu_1(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	*str;

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 100, 50, PURPLE_1, "~~ MAP INFO ~~");
	mlx_string_put(mlx, win, 20, 70, WHITE, "Map Name   :");
	mlx_string_put(mlx, win, 100, 70, WHITE,
		last_word(fdf->build->map_name, ' '));
	mlx_string_put(mlx, win, 20, 90, WHITE, "Width      :");
	mlx_string_put(mlx, win, 174, 90, WHITE, "Length     :");
	str = ft_itoa(fdf->map_width);
	mlx_string_put(mlx, win, 100, 90, WHITE, str);
	free(str);
	str = ft_itoa(fdf->map_height);
	mlx_string_put(mlx, win, 260, 90, WHITE, str);
	free(str);
	ft_menu_2(fdf);
}
