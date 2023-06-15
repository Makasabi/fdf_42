/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:47:34 by mrony             #+#    #+#             */
/*   Updated: 2023/05/20 15:57:42 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_exit_fail_fdfinit(t_build *build, char *str)
{
	int	y;

	y = 0;
	while (y < build->length)
	{
		free(build->map[y]);
		y++;
	}
	free(build->map);
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	ft_exit_fail_winptr(t_build *build, t_fdf *fdf, char *str)
{
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	ft_exit_fail_fdfinit(build, str);
}

void	ft_exit_fail_split(char **split, char **split_color, t_build *build)
{
	if (split_color)
	{
		ft_free_split(split_color, 3);
		free(split_color);
	}
	if (split)
	{
		ft_free_split(split, build->width);
		free(split);
	}
	if (build->maplist != NULL)
		ft_lstclear(&build->maplist, free);
	ft_putstr_fd((INVMAP), 2);
	ft_end_prog(build->map, build->length, build->map_name);
	exit (EXIT_FAILURE);
}

void	ft_exit_fail_read(char *line, t_list *maplist)
{
	free(line);
	if (maplist != NULL)
		ft_lstclear(&maplist, free);
	ft_putstr_fd((MALERROR), 2);
	exit (EXIT_FAILURE);
}
