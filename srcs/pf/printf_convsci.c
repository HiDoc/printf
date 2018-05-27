/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convsci.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:44:12 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/27 18:48:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		to_hformat(t_arg *arg, int exp)
{
	if (ABS(exp) < 10)
	{
		if (exp < 0)
		{
			arg->hformat[0] = '0';
			arg->hformat = ft_strrjoin("-", arg->hformat);
		}
		else
			arg->hformat = ft_strrjoin("+0", arg->hformat);
	}
}

static double	to_sci(double sci, t_arg *arg)
{
	int exp;

	exp = 0;
	if (ABS(sci) > 9)
		while (ABS(sci) > 9)
		{
			sci /= 10;
			exp++;
		}
	else if (ABS(sci) < 1)
		while (ABS(sci) < 1)
		{
			sci *= 10;
			exp--;
		}
	arg->hformat = ft_itoa(exp);
	to_hformat(arg, exp);
	arg->hformat = ft_strrjoin(arg->islower ? "e" : "E", arg->hformat);
	return (sci);
}

void			format_sci(t_arg *arg, va_list ap)
{
	double	sci;

	sci = va_arg(ap, double);
	if (!arg->hpreci || arg->preci < 6)
		arg->preci = 6;
	if (sci != 0)
	{
		sci = to_sci(sci, arg);
		arg->format = ft_strdjoin(befor_dot(sci), after_dot(sci, arg->preci));
		arg->format = ft_strdjoin(arg->format, arg->hformat);
	}
	else
		arg->format = ft_strdup(arg->islower ? "0e+00" : "0E+00");
}
