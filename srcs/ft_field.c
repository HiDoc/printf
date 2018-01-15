/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:00:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/15 13:03:58 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	field_str(t_args *args)
{
	size_t	count;
	char	*new;

	if (args->field == 0)
		return ;
	count = ft_abs(args->field) - ft_strlen(args->argument);
	if (count > 0)
	{
		new = ft_strnew(count + 1);
		new = ft_strset(new, ' ', count);
		if (args->field > 0)
			args->argument = ft_strdjoin(new, args->argument);
		else
			args->argument = ft_strdjoin(args->argument, new);
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
		if ((count = ft_strcount_if(arg->format, ft_isdigit)) > 0)
			if ((index == -1 && count > 0) || (index > 0 && count >
			ft_strcount_if(&arg->format[index], ft_isdigit)))
			{
				arg->field = ft_atoi(arg->format);
				field_str(arg);
			}
	}
}
