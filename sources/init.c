/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:32:45 by mrony             #+#    #+#             */
/*   Updated: 2023/05/20 18:23:16 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_build(t_build *build, char *str)
{
	build->split = NULL;
	build->width = 0;
	build->length = 0;
	build->height = 0;
	build->red = 255;
	build->green = 255;
	build->blue = 255;
	build->maplist = NULL;
	build->map = NULL;
	build->map_name = ft_strjoin("FdF : ", last_word(str, '/'));
	if (!build->map_name)
		build->map_name = "FdF";
}

t_map	**ft_create_map(t_build *build)
{
	t_map	**map;
	int		y;

	map = malloc(sizeof(t_map **) * build->length);
	if (!map)
	{
		ft_lstclear(&build->maplist, free);
		free(build->map_name);
		exit(EXIT_FAILURE);
	}
	y = -1;
	while (++y < build->length)
	{
		map[y] = malloc(sizeof(t_map) * build->width);
		if (!map[y])
		{
			ft_lstclear(&build->maplist, free);
			while (--y >= 0)
				free(map[y]);
			free(map);
			free(build->map_name);
			exit(EXIT_FAILURE);
		}
	}
	return (map);
}

t_fdf	ft_fdf_init(t_fdf fdf, t_build *build)
{
	fdf.map = build->map;
	fdf.map_width = build->width;
	fdf.map_height = build->length;
	fdf.map_max = 0;
	fdf.map_min = 0;
	fdf.build = build;
	fdf.proj = ISOMETRIC;
	fdf.trans_x = 0;
	fdf.trans_y = 0;
	fdf.zoom = 1 + (ft_bigger((((float)WINDOW_WIDTH * 9.0 / 10.0)
					/ ((float)fdf.map_width - 1.0) / 2.0),
				(((float)WINDOW_HEIGHT * 9.0 / 10.0)
					/ ((float)fdf.map_height - 1.0) / 2.0)));
	fdf.rot_x = 0;
	fdf.rot_y = 0;
	fdf.rot_z = 0;
	fdf.z_index = ft_z_index(&fdf, build->map);
	ft_color_array(&fdf);
	return (fdf);
}

void	ft_bres_data_init(t_bres *bres, t_point *start, t_point *end)
{
	bres->x = start->x;
	bres->y = start->y;
	bres->dx = end->x - start->x;
	bres->dy = end->y - start->y;
	bres->inc_x = ft_sgn(bres->dx);
	bres->inc_y = ft_sgn(bres->dy);
	bres->dx = ft_abs(bres->dx);
	bres->dy = ft_abs(bres->dy);
	bres->slope = 0;
	bres->error = 0;
	bres->error_inc = 0;
}

t_point	ft_init_p(t_map **map, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map[y][x].height;
	point.red = map[y][x].red;
	point.green = map[y][x].green;
	point.blue = map[y][x].blue;
	return (point);
}
