/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:13:13 by mrony             #+#    #+#             */
/*   Updated: 2023/05/22 18:05:05 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_build	build;

	if (ac == 2)
	{
		if (!ft_strstr(av[1], ".fdf"))
			return (ft_putstr_fd(strerror(EINVAL), 2), 0);
		ft_init_build(&build, av[1]);
		if (ft_read_map(av[1], &build) < 0)
			ft_lstclear(&build.maplist, free);
		if (ft_check_map(&build) < 0)
			return (ft_lstclear(&build.maplist, free),
				ft_putstr_fd((INVMAP), 2), 0);
		ft_map_parsing(&build);
		ft_mlx(&build);
	}
	else
		return (ft_putstr_fd(strerror(EINVAL), 2), 0);
}
