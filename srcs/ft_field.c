/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:00:37 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 17:11:53 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	field_str(t_args *args)
{
	size_t	count;
	char	*new;
	char	*tmp;

	count = ft_abs(args->field) - ft_strlen(args->argument);
	if (count > 0)
	{
		new = ft_strnew(count + 1);
		new = ft_strset(new, ' ', count);
		if (args->field > 0)
			args->argument = ft_strljoin(args->argument, new);
		else
		{
			tmp = ft_strdup(args->argument);
			free(args->argument);
			args->argument = ft_strjoin(new, tmp);
			free(tmp);
		}
		free(new);
	}
}

void		set_field(t_args *arg)
{
	int		index;
	int		count;

	count = 0;
	if (arg->format != NULL)
	{
		index = ft_strchri(arg->format, '.');
		while (index > 0 && arg->format[count] && ft_isdigit(arg->format[count]))
			count++;
		if (count < index || index == -1)
		{
			arg->field = ft_atoi(arg->format);
			field_str(arg);
		}
	}
}
