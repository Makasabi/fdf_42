/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:49:24 by mrony             #+#    #+#             */
/*   Updated: 2023/05/19 16:21:56 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

t_color	ft_decode_color(int cc)
{
	t_color	color;

	color.red = (cc >> 16) & 0xFF;
	color.green = (cc >> 8) & 0xFF;
	color.blue = cc & 0xFF;
	return (color);
}

float	ft_percent(int current, int start, int end)
{
	float	distance;
	float	progression;

	distance = (float)end - (float)start;
	progression = (float)current - (float)start;
	if (distance == 0.0)
		return (1.0);
	else
		return (progression / distance);
}

int	ft_gradient(t_bres *bres, t_point *start, t_point *end)
{
	float	percent;
	int		red;
	int		green;
	int		blue;

	if (ft_encode_rgb(start->red, start->green, start->blue)
		== ft_encode_rgb(end->red, end->green, end->blue))
		return (ft_encode_rgb(start->red, start->green, start->blue));
	if (bres->dx > bres->dy)
		percent = ft_percent(bres->x, start->x, end->x);
	else
		percent = ft_percent(bres->y, start->y, end->y);
	red = (1 - percent) * start->red + percent * end->red;
	green = (1 - percent) * start->green + percent * end->green;
	blue = (1 - percent) * start->blue + percent * end->blue;
	return (ft_encode_rgb(red, green, blue));
}

void	ft_reset_colors(t_fdf *fdf, t_map **map)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < fdf->map_height - 1)
	{
		x = -1;
		while (x++ < fdf->map_width - 1)
		{
			map[y][x].red = map[y][x].r_reset;
			map[y][x].green = map[y][x].g_reset;
			map[y][x].blue = map[y][x].b_reset;
		}
	}
}
