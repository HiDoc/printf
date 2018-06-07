/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/06 10:27:47 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_arg	*set_format(t_arg *new, va_list ap)
{
	set_wildcards(new, ap);
	if (new->ismins)
		new->is0 = 0;
	if (new->isplus)
		new->ispace = 0;
	if (new->isl && (is_char(new) || is_str(new)))
		new->islower = 0;
	if (is_num(new))
		format_num(new, ap);
	else if (is_char(new) || is_string(new))
		switch_char(new, ap);
	else if (new->arg == 'f' || new->arg == 'F')
		format_float(new, ap);
	else if (new->arg == 'e' || new->arg == 'E')
		format_sci(new, ap);
	else if (new->arg == 'g' || new->arg == 'G')
		format_gen(new, ap);
	else if (new->arg == '%')
		format_htg(new);
	return (new);
}
