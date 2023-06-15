/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:10:14 by mrony             #+#    #+#             */
/*   Updated: 2023/05/20 17:52:32 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_end_prog(t_map **map, int height, char *map_name)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(map[y]);
		y++;
	}
	free(map);
	free (map_name);
}

int	ft_is_char_here(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_split(char **split, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		i++;
	}
}

static float	ft_z_cont(int x)
{
	int	i;
	int	y;

	i = 0;
	y = x;
	while (y > 0)
	{
		y = y / 10;
		i++;
	}
	if (x < 10)
		return (3);
	x = x / pow(10, i - 2) - 5;
	return (x);
}

float	ft_z_index(t_fdf *fdf, t_map **map)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < fdf->map_height - 1)
	{
		x = -1;
		while (x++ < fdf->map_width - 1)
		{
			if (fdf->map_max < map[y][x].height)
				fdf->map_max = map[y][x].height;
			if (fdf->map_min > map[y][x].height)
				fdf->map_min = map[y][x].height;
		}
	}
	return (ft_z_cont(fdf->map_max));
}
