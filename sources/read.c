/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:41:01 by mrony             #+#    #+#             */
/*   Updated: 2023/05/11 12:50:12 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_map_width(char *line)
{
	int	trigger;
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	trigger = 0;
	while (line[i])
	{
		if (trigger == 0 && line[i] != ' ' && line[i] != '\n')
		{
			wc++;
			trigger = 1;
		}
		else if (trigger == 1 && (line[i] == ' ' || line[i] == '\n'))
			trigger = 0;
		i++;
	}
	return (wc);
}

static int	ft_read_map_cont(char *line, int fd, t_build *build)
{
	t_list	*new_node;
	int		linecount;

	linecount = 0;
	build->maplist = ft_lstnew(ft_strdup(line));
	if (!build->maplist)
		ft_exit_fail_read(line, build->maplist);
	linecount++;
	build->width = ft_map_width(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_node = ft_lstnew(ft_strdup(line));
		if (!new_node)
			ft_exit_fail_read(line, build->maplist);
		linecount++;
		ft_lstadd_back(&build->maplist, new_node);
		free(line);
	}
	build->length = linecount;
	free(line);
	return (0);
}

int	ft_read_map(char *str, t_build *build)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		perror("Opening map");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
		ft_exit_fail_read(line, build->maplist);
	if (ft_read_map_cont(line, fd, build) < 0)
		return (-1);
	close(fd);
	return (0);
}
