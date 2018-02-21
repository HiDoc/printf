/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convflt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:36:51 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/21 18:18:19 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_float(t_arg *arg, va_list ap)
{
	double		num;
	double		tmpfloat;
	double		ten;
	long int	before;
	long int	after;
	char		*aftertmp;
	char		*field;
	size_t		count;

	if (!arg->hpreci || arg->preci < 6)
		arg->preci = 6;
	before = 0;
	count = (size_t)arg->preci;
	tmpfloat = 0;
	num = 0;
	ten = 10.000000;
	num = va_arg(ap, double);
	before = (long int)num;
	tmpfloat = (num - (double)before);	
	while (count > 0)
	{
		tmpfloat = tmpfloat * ten;
		count--;
	}
	tmpfloat = ABS(tmpfloat);
	if (arg->preci < 7 && (num - (double)before) != 0 && before < 10 && before)
		tmpfloat++;
	after = (long int)tmpfloat;
	aftertmp = ft_lltoa(after);
	if ((count = ft_strlen(aftertmp)) < (size_t)arg->preci)
	{
		field = ft_strnew(arg->preci - count);
		ft_strset(field, '0', arg->preci - count);
		aftertmp = ft_strdjoin(aftertmp, field);
	}
	arg->format = ft_strdjoin(ft_strljoin(ft_lltoa(before), "."), aftertmp);
}
