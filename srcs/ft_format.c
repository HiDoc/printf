/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/15 16:54:21 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_args		*ft_map_args(t_args *list, va_list ap)
{
	t_args	*map;
	int		index;
	char	*tmp;

	map = list;
	while (map)
	{
		index = set_attribute(map);
		if (index > -1)
		{
			map->argument = set_argument(map, ap);
			tmp = ft_strdup(map->line);
			map->format = ft_strsub(tmp, 0, index);
			free(map->line);
			map->line = ft_strsub(tmp, index + 1, ft_strlen(tmp));
			free(tmp);
			set_precision(map);
			set_field(map);
		}
		map = map->next;
	}
	return (list);
}

char		*ft_format(const char *format, va_list ap)
{
	char	**store;
	int		count;
	t_args	*args;
	t_args	*start;

	count = 0;
	store = ft_strsplit(format, '%');
	if (store[count])
	{
		args = ft_new_arg(store[count]);
		start = args;
		count++;
	}
	else if (ft_strlen(format) == 2)
		return (ft_strdup("%"));
	while (store[count])
	{
		args->next = ft_new_arg(store[count]);
		args = args->next;
		count++;
	}
	free(store);
	ft_map_args(start, ap);
	return (ft_join_arg(start));
}
