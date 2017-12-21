/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 10:36:11 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 12:55:23 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_free_arg(t_args *arg)
{
	if (arg->line != NULL)
		free(arg->line);
	if (arg->flags != NULL)
		free(arg->flags);
	if (arg->argument != NULL)
		free(arg->argument);
	free(arg);
}

void	ft_map_args(t_args *list, va_list ap)
{
	t_args	*map;

	map = list;
	while (map)
	{
		set_argument(map, ap);
		set_precision(map);
		set_field(map);
		map = map->next;
	}
}

char	*ft_join_arg(t_args *list)
{
	char	*str;
	char	*tmp;
	t_args	*next;

	if (list->argument != NULL)
		str = ft_strjoin(list->line, list->argument);
	else
		str = ft_strdup(list->line);
	next = list->next;
	ft_free_arg(list);
	while (next)
	{
		if (next->argument != NULL)
		{
			tmp = ft_strjoin(next->argument, next->line);
			str = ft_strljoin(str, tmp);
			free(tmp);
		}
		else
			str = ft_strljoin(str, next->line);
		list = next;
		next = next->next;
		ft_free_arg(list);
	}
	return (str);
}

t_args	*ft_new_arg(char *str)
{
	t_args *new;
	int count;

	count = 0;
	if ((new = (t_args *)malloc(sizeof(t_args))) == NULL)
		return (NULL);
	if (ft_isargument(str[0]))
		count++;
	if (count == 0)
	{
		new->line = ft_strdup(str);
		new->flags = NULL;
		new->attribut = '0';
	}
	else
	{
		new->line = ft_strsub(str, count, (int)ft_strlen(str));
		new->flags = ft_strsub(str, 0, count);
		new->attribut = str[0];
	}
	new->argument = NULL;
	new->precision = -1;
	new->field = -1;
	free(str);
	return (new);
}
