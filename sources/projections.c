/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:16:17 by mrony             #+#    #+#             */
/*   Updated: 2023/05/19 16:40:04 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_iso(int *x, int *y, int z)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (int)((temp_x - temp_y) * cos(M_PI / 6.0));
	*y = (int)((temp_x + temp_y) * sin(M_PI / 6.0) - z);
}

void	ft_rot_x(int *y, int *z, float rot_x)
{
	int	temp_y;

	temp_y = *y;
	*y = temp_y * cos(rot_x) + *z * sin(rot_x);
	*z = -temp_y * sin(rot_x) + *z * cos(rot_x);
}

void	ft_rot_y(int *x, int *z, float rot_y)
{
	int	temp_x;

	temp_x = *x;
	*x = temp_x * cos(rot_y) + *z * sin(rot_y);
	*z = -temp_x * sin(rot_y) + *z * cos(rot_y);
}

void	ft_rot_z(int *x, int *y, float rot_z)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = temp_x * cos(rot_z) - temp_y * sin(rot_z);
	*y = temp_x * sin(rot_z) + temp_y * cos(rot_z);
}

t_point	ft_proj(t_fdf *fdf, t_point point)
{
	point.x *= fdf->zoom;
	point.y *= fdf->zoom;
	point.z *= fdf->zoom / fdf->z_index;
	point.x -= (fdf->map_width * fdf->zoom) / 2;
	point.y -= (fdf->map_height * fdf->zoom) / 2;
	ft_rot_x(&point.y, &point.z, fdf->rot_x);
	ft_rot_y(&point.x, &point.z, fdf->rot_y);
	ft_rot_z(&point.x, &point.y, fdf->rot_z);
	if (fdf->proj == ISOMETRIC)
		ft_iso(&point.x, &point.y, point.z);
	if (fdf->proj == SIDE)
		ft_rot_x(&point.y, &point.z, -M_PI / 2);
	point.x += WINDOW_WIDTH / 2 + fdf->trans_x;
	point.y += WINDOW_HEIGHT / 2 + fdf->trans_y;
	return (point);
}
