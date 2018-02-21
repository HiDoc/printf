/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_wildcards.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:33:13 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/21 12:33:16 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_wildcards(t_arg *new, va_list ap)
{
	if (new->wildfield)
	{
		if ((new->wildfield = va_arg(ap, int)) < 0 && !new->field)
			new->ismins = 1;
		if (!new->field)
			new->field = ABS(new->wildfield);
	}
	if (new->wildpreci)
	{
		new->preci = va_arg(ap, int);
		new->hpreci = new->preci > -1;
	}
}
