/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 10:36:11 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/15 13:04:50 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_free_arg(t_args *arg)
{
	if (arg->line != NULL)
		free(arg->line);
	if (arg->format != NULL)
		free(arg->format);
	if (arg->argument != NULL)
		free(arg->argument);
	free(arg);
}

char	*ft_join_arg(t_args *list)
{
	char	*str;
	char	*tmp;
	t_args	*next;

	if (list->argument != NULL)
		str = ft_strjoin(list->argument, list->line);
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
	t_args	*new;

	if ((new = (t_args *)malloc(sizeof(t_args))) == NULL)
		return (NULL);
	new->attribut = '0';
	new->line = ft_strdup(str);
	new->argument = NULL;
	new->format = NULL;
	new->precision = -1;
	new->field = 0;
	free(str);
	return (new);
}
