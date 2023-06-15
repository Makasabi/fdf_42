/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:16:51 by mrony             #+#    #+#             */
/*   Updated: 2023/05/11 14:34:02 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_clean_line(t_list *maplist)
{
	int		len;
	t_list	*cpy;
	char	*str;

	cpy = maplist;
	while (cpy)
	{
		str = (char *)cpy->content;
		len = ft_strlen(str);
		len--;
		if (str[len] == '\n')
			(str[len] = '\0');
		cpy = cpy->next;
	}
}

static char	*ft_str_check(char *str)
{
	if (!(ft_isdigit(*str)))
		return (NULL);
	while (*str != ' ' && *str != ',' && *str)
	{
		if (!(ft_isdigit(*str)))
			return (NULL);
		str++;
	}
	if (*str == ',')
	{
		if (*(str + 1) != '0' && *(str + 2) != 'x')
			return (NULL);
		str += 3;
		while (*str != ' ' && *str)
		{
			if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'f')
				&& (*str < 'A' || *str > 'F'))
				return (NULL);
			if (*str >= 'A' && *str <= 'F')
				*str = ft_tolower(*str);
			str++;
		}
	}
	return (str);
}

int	ft_line_check(char *line)
{
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line == '+' || *line == '-')
			line++;
		line = ft_str_check(line);
		if (!line)
			return (-1);
		while (*line == ' ')
			line++;
	}
	return (0);
}

static int	ft_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (-1);
}

int	ft_check_map(t_build *build)
{
	t_list	*cpy;
	char	*str;

	cpy = build->maplist;
	ft_clean_line(build->maplist);
	while (cpy)
	{
		str = (char *)cpy->content;
		if (ft_empty_line(str) < 0)
			return (-1);
		if (ft_line_check(str) < 0)
			return (-1);
		if (ft_map_width(str) != build->width)
			return (-1);
		cpy = cpy->next;
	}
	return (0);
}
