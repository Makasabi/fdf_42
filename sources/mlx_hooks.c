/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:34:46 by mrony             #+#    #+#             */
/*   Updated: 2023/05/19 16:37:09 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_handle_mouse(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 4)
		fdf->zoom += 3;
	if (button == 5 && fdf->zoom > 3)
		fdf->zoom -= 3;
	return (0);
}

int	ft_reset_prog(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->win_ptr = NULL;
	}
	if (key == XK_p)
		ft_restart(fdf, PARALLEL);
	if (key == XK_i)
		ft_restart(fdf, ISOMETRIC);
	if (key == XK_o)
		ft_restart(fdf, SIDE);
	return (0);
}

int	ft_move_map(int key, t_fdf *fdf)
{
	if (key == XK_Left)
		fdf->trans_x -= 3;
	if (key == XK_Right)
		fdf->trans_x += 3;
	if (key == XK_Down)
		fdf->trans_y += 3;
	if (key == XK_Up)
		fdf->trans_y -= 3;
	if (key == XK_z)
		fdf->rot_z += 0.03;
	if (key == XK_a)
		fdf->rot_z -= 0.03;
	if (key == XK_x)
		fdf->rot_x += 0.03;
	if (key == XK_s)
		fdf->rot_x -= 0.03;
	if (key == XK_c)
		fdf->rot_y += 0.03;
	if (key == XK_d)
		fdf->rot_y -= 0.03;
	if (key == XK_l)
		fdf->z_index += 0.1;
	if (key == XK_h && fdf->z_index > 0.2)
		fdf->z_index -= 0.1;
	return (0);
}

int	ft_handle_keypress(int key, t_fdf *fdf)
{
	static int	i;

	if (key == XK_Escape || key == XK_p || key == XK_i || key == XK_o
		|| key == XK_w)
		ft_reset_prog(key, fdf);
	if (key == XK_Left || key == XK_Down || key == XK_Right || key == XK_Up
		|| key == XK_z || key == XK_a || key == XK_x || key == XK_s
		|| key == XK_c || key == XK_d || key == XK_l || key == XK_h)
		ft_move_map(key, fdf);
	if (key == XK_q)
	{
		ft_color_preset(fdf, fdf->map, ft_decode_color(fdf->colors[i]),
			ft_decode_color(fdf->colors[i + 1]));
		if (i < 10)
			i += 1;
		else
			i = 0;
	}
	if (key == XK_w)
		ft_color_lgbt(fdf, fdf->map);
	if (key == XK_e)
		ft_reset_colors(fdf, fdf->map);
	return (0);
}

int	ft_handle_destroy_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->win_ptr = NULL;
	return (0);
}
