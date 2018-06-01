/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:43:32 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/01 15:28:07 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long int	get_num(t_arg *new, va_list ap, int isunsign)
{
	long long int	num;

	num = 0;
	if (!isunsign)
	{
		if (new->isl == 2 || new->isj)
			num = va_arg(ap, long long);
		else if (new->isl == 1 || !(new->islower) || new->isz)
			num = va_arg(ap, long);
		else
			num = va_arg(ap, int);
	}
	else
	{
		if (new->isl == 2 || new->isz)
			num = va_arg(ap, unsigned long long);
		else if (new->isj)
			num = va_arg(ap, long long);
		else if (new->arg == 'U' || new->isl == 1 || new->arg == 'O')
			num = va_arg(ap, unsigned long);
		else
			num = va_arg(ap, unsigned int);
	}
	return (num);
}

static void				get_base(long long int num, t_arg *new, char *basef)
{
	int		baseto;

	baseto = 10;
	if (is_octal(new) || is_hexa(new))
		baseto = (is_octal(new) ? 8 : 16);
	if (is_deci(new))
	{
		if (new->isl == 2 || new->isj)
			new->format = ft_lltoa(num);
		else if (new->isl == 1 || !(new->islower) || new->isz)
			new->format = ft_ltoa(num);
		else
			new->format = ft_itoa(num);
	}
	else
	{
		if (new->isl == 2 || new->isz)
			new->format = ft_ulltoabase(num, baseto, basef);
		else if (new->isj)
			new->format = ft_ulltoabase(num, baseto, basef);
		else if (new->arg == 'U' || new->isl == 1 || is_octal(new))
			new->format = ft_ultoabase(num, baseto, basef);
		else
			new->format = ft_itoabase(num, baseto, basef);
	}
}

void					switch_num(t_arg *new, va_list ap)
{
	long long int	num;

	if (new->arg == 'p')
	{
		new->isl = 2;
		new->ishtg = 1;
	}
	num = get_num(new, ap, !(is_deci(new)));
	if (new->ish == 1 && new->arg != 'U')
		num = is_deci(new) && new->islower ? (short)num : (unsigned short)num;
	if (new->ish == 2 && !(ft_strchri("DOU", new->arg) > -1))
		num = is_deci(new) && new->islower ? (signed char)num :
			(unsigned char)num;
	get_base(num, new, new->islower ? "0123456789abcdef" : "0123456789ABCDEF");
}
