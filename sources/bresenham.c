/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:59:44 by mrony             #+#    #+#             */
/*   Updated: 2023/05/19 16:31:41 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_horizontal(t_bres *bres, t_fdf *fdf, t_point *start, t_point *end)
{
	while (bres->y != end->y)
	{
		img_pix_put(fdf, bres->x, bres->y, ft_gradient(bres, start, end));
		bres->y += bres->inc_y;
	}
}

void	ft_vertical(t_bres *bres, t_fdf *fdf, t_point *start, t_point *end)
{
	while (bres->x != end->x)
	{
		img_pix_put(fdf, bres->x, bres->y, ft_gradient(bres, start, end));
		bres->x += bres->inc_x;
	}
}

void	ft_octant_h(t_bres *bres, t_fdf *fdf, t_point *start, t_point *end)
{
	bres->slope = 2 * bres->dy;
	bres->error = -bres->dx;
	bres->error_inc = -2 * bres->dx;
	while (bres->x != end->x + bres->inc_x)
	{
		img_pix_put(fdf, bres->x, bres->y, ft_gradient(bres, start, end));
		bres->error += bres->slope;
		if (bres->error >= 0)
		{
			bres->y += bres->inc_y;
			bres->error += bres->error_inc;
		}
		bres->x += bres->inc_x;
	}
}

void	ft_octant_v(t_bres *bres, t_fdf *fdf, t_point *start, t_point *end)
{
	bres->slope = 2 * bres->dx;
	bres->error = -bres->dy;
	bres->error_inc = -2 * bres->dy;
	while (bres->y != end->y + bres->inc_y)
	{
		img_pix_put(fdf, bres->x, bres->y, ft_gradient(bres, start, end));
		bres->error += bres->slope;
		if (bres->error >= 0)
		{
			bres->x += bres->inc_x;
			bres->error += bres->error_inc;
		}
		bres->y += bres->inc_y;
	}
}

void	ft_bresen(t_fdf *fdf, t_point start, t_point end)
{
	t_bres	bres;

	ft_bres_data_init(&bres, &start, &end);
	if (bres.dx == 0)
		ft_horizontal(&bres, fdf, &start, &end);
	else if (bres.dy == 0)
		ft_vertical(&bres, fdf, &start, &end);
	else if (bres.dx >= bres.dy)
		ft_octant_h(&bres, fdf, &start, &end);
	else if (bres.dx <= bres.dy)
		ft_octant_v(&bres, fdf, &start, &end);
}
