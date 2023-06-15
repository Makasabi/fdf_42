/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:49:50 by mrony             #+#    #+#             */
/*   Updated: 2023/05/20 18:08:01 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_map_builder(t_build *build, t_map **map)
{
	static int	x = 0;
	static int	y = 0;

	map[y][x].height = build->height;
	map[y][x].red = build->red;
	map[y][x].green = build->green;
	map[y][x].blue = build->blue;
	map[y][x].r_reset = build->red;
	map[y][x].g_reset = build->green;
	map[y][x].b_reset = build->blue;
	if (x < build->width - 1)
		x++;
	else
	{
		x = 0;
		if (y < build->length - 1)
			y++;
		else
			return ;
	}
}

void	ft_isolate_rgb(t_build *build, char *color)
{
	int	len;

	color = color + 2;
	len = ft_strlen(color);
	if (len >= 1 && len <= 2)
	{
		build->red = 0;
		build->green = 0;
		build->blue = ft_atoi_hexa(color);
	}
	else if (len >= 3 && len <= 4)
	{
		build->blue = ft_atoi_hexa(color + 2);
		color[2] = '\0';
		build->green = ft_atoi_hexa(color);
		build->red = 0;
	}
	else if (len >= 5 && len <= 6)
	{
		build->blue = ft_atoi_hexa(color + 4);
		color[4] = '\0';
		build->green = ft_atoi_hexa(color + 2);
		color[2] = '\0';
		build->red = ft_atoi_hexa(color);
	}
}

void	ft_parse_color(t_build *build, char **split, int *i)
{
	char	**split_color;
	long	height;

	(void)i;
	split_color = ft_split(split[*i], ',');
	if (!split_color)
		ft_exit_fail_split(split, split_color, build);
	if (ft_strlen(split_color[0]) <= 11)
		height = ft_atol(split_color[0]);
	else
		ft_exit_fail_split(split_color, split, build);
	if (height >= -2147483648 && height <= 2147483647)
		build->height = (int)height;
	else
		ft_exit_fail_split(split_color, split, build);
	ft_isolate_rgb(build, split_color[1]);
	ft_map_builder(build, build->map);
	ft_free_split(split_color, 2);
	free(split_color);
	build->blue = 255;
	build->red = 255;
	build->green = 255;
}

void	ft_parse_point(t_build *build, char **split)
{
	int		i;
	long	height;

	i = -1;
	while (split[++i])
	{
		if (ft_is_char_here(split[i], ',') == 1)
			ft_parse_color(build, split, &i);
		else
		{
			if (ft_strlen(split[i]) <= 11)
				height = ft_atol(split[i]);
			if (height >= -2147483648 && height <= 2147483647)
				build->height = (int)height;
			else
			{
				ft_free_split(split, build->width);
				ft_lstclear(&build->maplist, free);
				ft_putstr_fd((INVMAP), 2);
				free(build->map_name);
				exit (EXIT_FAILURE);
			}
			ft_map_builder(build, build->map);
		}
	}
}

void	ft_map_parsing(t_build *build)
{
	t_list	*cpy;
	char	**split;

	build->map = ft_create_map(build);
	cpy = build->maplist;
	while (cpy)
	{
		split = ft_split(cpy->content, ' ');
		if (!split)
		{
			ft_lstclear(&build->maplist, free);
			ft_end_prog(build->map, build->length, build->map_name);
			exit(EXIT_FAILURE);
		}
		ft_parse_point(build, split);
		ft_free_split(split, build->width);
		free(split);
		cpy = cpy->next;
	}
	ft_lstclear(&build->maplist, free);
}
