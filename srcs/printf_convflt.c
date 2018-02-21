/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convflt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:36:51 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/21 21:13:46 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*befor_dot(double num)
{
	long long before;

	before = (long long)num;
	return (ft_strljoin(ft_lltoa(before), "."));
}

static char	*after_dot(double num, size_t count)
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
	if (!(ABS((after - (long int)after)) * 10 < 5))
		after++;
	if (count_zero - 1)
	{
		tmp = ft_strnew(count_zero - 1);
		ft_strset(tmp, '0', count_zero - 1);
		return (ft_strdjoin(tmp, ft_lltoa((long long)after)));
	}
	return (ft_lltoa((long long)after));
}

void		format_float(t_arg *arg, va_list ap)
{
	double		num;
	size_t		count;
	size_t		preci;
	char		*tmp;
	char		*field;

	if (!arg->hpreci || arg->preci < 6)
		arg->preci = 6;
	num = va_arg(ap, double);
	preci = (size_t)arg->preci;
	tmp = after_dot(num, (size_t)arg->preci);
	if ((count = ft_strlen(tmp)) < preci)
	{
		field = ft_strnew(preci - count);
		ft_strset(field, '0', preci - count);
		tmp = ft_strdjoin(tmp, field);
	}
	arg->format = ft_strdjoin(befor_dot(num), tmp);
}
