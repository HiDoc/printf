/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:59:12 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/15 13:08:12 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_precision(t_args *arg)
{
	int index;
	int precision;

	precision = 0;
	if (arg->format != NULL && arg->attribut != 's')
	{
		index = ft_strchri(arg->format, '.');
		if (index != -1)
			precision = ft_atoi(&(arg->format[index + 1]));
	}
	arg->precision = precision;
}
