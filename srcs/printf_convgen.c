/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convgen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:05:52 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/16 14:32:38 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static double	to_gen(t_arg *arg, int exp, va_list ap)
{
	if (exp < -4 || ABS(exp) >= arg->preci)
	{
		if (exp < 0)
		{
			arg->hformat[0] = '0';
			arg->hformat = ft_strrjoin("-", arg->hformat);
		}
		else
			arg->hformat = ft_strrjoin("+0", arg->hformat);
	}
	else
	{
		free(arg->hformat);
		arg->hformat = NULL;
		format_float(arg, ap);
		return (0);
	}
	return (1);
}

static double	to_sci(double sci, t_arg *arg, va_list ap)
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
	if (!(to_gen(arg, exp, ap)))
		return (0);
	arg->hformat = ft_strrjoin(arg->islower ? "e" : "E", arg->hformat);
	return (sci);
}

static char		*after_gen(double num, size_t count)
{
	double		after;
	char		*tmp;
	size_t		count_zero;

	count_zero = 0;
	after = num - (long int)num;
	while (count > 0)
	{
		if (!((int)after))
			count_zero++;
		after *= 10;
		count--;
	}
	after = ABS(after);
	if (!(ABS((after - (long long)after)) * 10 < 5))
		after++;
	while (((long long)after) % 10 == 0)
		after /= 10;
	if (count_zero - 1)
	{
		tmp = ft_strnew(count_zero - 1);
		ft_strset(tmp, '0', count_zero - 1);
		return (ft_strdjoin(tmp, ft_lltoa((long long)after)));
	}
	return (ft_lltoa((long long)after));
}

void			format_gen(t_arg *arg, va_list ap)
{
	double	num;

	if (!arg->hpreci)
		arg->preci = 6;
	if (arg->preci == 0)
		arg->preci = 1;
	num = va_arg(ap, double);
	num = to_sci(num, arg, ap);
	if (arg->hformat)
	{
		arg->format = ft_strdjoin(befor_dot(num),
				after_gen(num, arg->preci - 1));
		arg->format = ft_strdjoin(arg->format, arg->hformat);
	}
}
