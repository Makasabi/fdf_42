/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:50:43 by mrony             #+#    #+#             */
/*   Updated: 2023/05/20 18:37:03 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_restart(t_fdf *fdf, t_proj proj)
{
	fdf->proj = proj;
	fdf->trans_x = 0;
	fdf->trans_y = 0;
	fdf->zoom = 1 + (ft_bigger((((float)WINDOW_WIDTH * 9.0 / 10.0)
					/ ((float)fdf->map_width - 1.0) / 2.0),
				(((float)WINDOW_HEIGHT * 9.0 / 10.0)
					/ ((float)fdf->map_height - 1.0) / 2.0)));
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
	fdf->z_index = ft_z_index(fdf, fdf->map);
}

void	render_background(t_fdf *fdf, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(fdf, j++, i, color);
		++i;
	}
}

int	ft_render(t_fdf *fdf)
{
	int		y;
	int		x;
	t_point	s;

	y = 0;
	if (fdf->win_ptr == NULL)
		return (1);
	render_background(fdf, GREY_PIXEL);
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			s = ft_proj(fdf, ft_init_p(fdf->map, x, y));
			if (x < fdf->map_width - 1)
				ft_bresen(fdf, s, ft_proj(fdf, ft_init_p(fdf->map, x + 1, y)));
			if (y < fdf->map_height - 1)
				ft_bresen(fdf, s, ft_proj(fdf, ft_init_p(fdf->map, x, y + 1)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->mlx_img, 0, 0);
	ft_menu_1(fdf);
	return (0);
}
