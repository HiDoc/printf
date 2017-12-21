/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:00:37 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 12:49:10 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_field(t_args *arg)
{
	int		index;
	int		count;

	count = 0;
	if (arg->flags != NULL)
	{
		index = ft_strchri(arg->flags, '.');
		while (arg->flags[count] && count < index && !ft_isdigit(arg->flags[count]))
			count++;
		if (count < index)
			arg->field = ft_atoi(arg->flags);
	}
}
