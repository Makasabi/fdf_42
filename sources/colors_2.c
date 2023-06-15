/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:21:22 by mrony             #+#    #+#             */
/*   Updated: 2023/05/31 11:11:04 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_color_preset(t_fdf *fdf, t_map **map, t_color start_c, t_color end_c)
{
	int		x;
	int		y;
	float	percent;

	y = -1;
	while (y++ < fdf->map_height - 1)
	{
		x = -1;
		while (x++ < fdf->map_width - 1)
		{
			percent = ft_percent(map[y][x].height, fdf->map_min, fdf->map_max);
			map[y][x].red
				= (1 - percent) * start_c.red + percent * end_c.red;
			map[y][x].green
				= (1 - percent) * start_c.green + percent * end_c.green;
			map[y][x].blue
				= (1 - percent) * start_c.blue + percent * end_c.blue;
		}
	}
}

void	ft_color_array(t_fdf *fdf)
{
	fdf->colors[0] = MARS_H;
	fdf->colors[1] = MARS_L;
	fdf->colors[2] = UNICORN_H;
	fdf->colors[3] = UNICORN_L;
	fdf->colors[4] = BEACH_H;
	fdf->colors[5] = BEACH_L;
	fdf->colors[6] = TRON;
	fdf->colors[7] = TRON;
	fdf->colors[8] = FOREST_H;
	fdf->colors[9] = FOREST_L;
	fdf->colors[10] = SPACE_H;
	fdf->colors[11] = SPACE_L;
}

t_color	ft_choose_color(t_fdf *fdf, t_color color, int y)
{
	if (y < (double)fdf->map_height / 6.0)
		color = ft_decode_color(LGBT_RED);
	if (y < ((double)fdf->map_height / 6.0) * 2
		&& y >= (double)fdf->map_height / 6.0)
		color = ft_decode_color(LGBT_ORANGE);
	if (y < ((double)fdf->map_height / 6.0) * 3
		&& y >= ((double)fdf->map_height / 6.0) * 2)
		color = ft_decode_color(LGBT_YELLOW);
	if (y < ((double)fdf->map_height / 6.0) * 4
		&& y >= ((double)fdf->map_height / 6.0) * 3)
		color = ft_decode_color(LGBT_GREEN);
	if (y < ((double)fdf->map_height / 6.0) * 5
		&& y >= ((double)fdf->map_height / 6.0) * 4)
		color = ft_decode_color(LGBT_BLUE);
	if (y >= ((double)fdf->map_height / 6.0) * 5)
		color = ft_decode_color(LGBT_PURPLE);
	return (color);
}

void	ft_color_lgbt(t_fdf *fdf, t_map **map)
{
	int		y;
	int		x;
	t_color	color;

	y = -1;
	while (y++ < fdf->map_height - 1)
	{
		color = ft_choose_color(fdf, color, y);
		x = -1;
		while (x++ < fdf->map_width - 1)
		{
			map[y][x].red = color.red;
			map[y][x].green = color.green;
			map[y][x].blue = color.blue;
		}
	}
}
