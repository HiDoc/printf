/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/11 11:42:32 by fmadura          ###   ########.fr       */
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
		else if (new->arg == 'U' || new->isl == 1)
			num = va_arg(ap, unsigned long);
		else
			num = va_arg(ap, unsigned int);
	}
	return (num);
}

static void				get_decimal(t_arg *new, va_list ap)
{
	long long int	num;

	num = get_num(new, ap, 0);
	if (new->ish == 1)
		num = (short)num;
	if (new->ish == 2)
		num = (signed char)num;
	new->format = ft_ltoabase(num, 10, "0123456789", 0);
}

static void				get_unsigned(t_arg *new, va_list ap)
{
	long long int	num;
	int				sign;
	int				base;

	sign = 0;
	base = 10;
	if (new->arg == 'p')
	{
		new->isl = 2;
		new->ishtg = 1;
	}
	num = get_num(new, ap, 1);
	if (is_unsign(new))
		sign = 4;
	if (is_octal(new) || is_hexa(new))
		base = (is_octal(new) ? 8 : 16);
	if (new->ish && !sign)
		num = (new->ish == 2 ? (unsigned char)num : (short)num);
	if (new->isj == 1 || new->isl)
		sign = 6;
	new->format = ft_ltoabase(num, base, new->islower ?
			"0123456789abcdef" : "0123456789ABCDEF", sign);
}

static void				get_char(t_arg *new, va_list ap)
{
	if (is_char(new))
		new->char0 = va_arg(ap, int);
	else
	{
		if (!new->islower || new->isl)
			new->wformat = ft_wstrdup(va_arg(ap, wchar_t *));
		else
		{
			new->format = ft_strdup2(va_arg(ap, char *));
			if (new->format == NULL)
				new->format = ft_strdup("(null)");
		}
	}
}

void					set_format(t_arg *new, va_list ap)
{
	long long	num;
	int			base;
	int			sign;

	sign = 0;
	num = 0;
	base = 10;
	if (is_num(new))
	{
		if (is_deci(new))
			get_decimal(new, ap);
		else
			get_unsigned(new, ap);
	}
	else if (is_char(new) || is_string(new))
		get_char(new, ap);
	if (is_num(new))
		format_num(new);
	else if (is_string(new))
		format_str(new);
	else
		format_char(new);
}
