/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:59:12 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 12:47:27 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_precision(t_args *arg)
{
	int index;

	if (arg->flags != NULL)
	{
		index = ft_strchri(arg->flags, '.');
		if (index != -1)
			arg->precision = ft_atoi(&(arg->flags[index]));
	}
}
