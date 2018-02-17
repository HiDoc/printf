/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/17 19:53:52 by fmadura          ###   ########.fr       */
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
		else if (new->arg == 'U' || new->isl == 1 || is_octal(new))
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

static void				switch_num(t_arg *new, va_list ap)
{
	long long int	num;

	if (new->arg == 'p')
	{
		new->isl = 2;
		new->ishtg = 1;
	}
	num = get_num(new, ap, !(is_deci(new)));
	if (new->ish == 1 && !is_unsign(new))
		num = (short)num;
	if (new->ish == 2)
		num = is_deci(new) ? (signed char)num : (unsigned char)num;
	get_base(num, new, new->islower ? "0123456789abcdef" : "0123456789ABCDEF");
}

static void				get_chars(t_arg *new, va_list ap)
{
	if (is_char(new))
	{
		new->char0 = va_arg(ap, int);
		format_char(new);
	}
	else
	{
		if (!new->islower)
		{
			new->wformat = ft_wstrdup(va_arg(ap, wchar_t *));
			if (!(checkwstr(new)))
				new->error = 1;
			if (new->wformat == NULL)
				new->wformat = str_to_wstr("(null)");
		}
		else
		{
			new->format = ft_strdup2(va_arg(ap, char *));
			if (new->format == NULL)
				new->format = ft_strdup("(null)");
		}
		format_str(new);
	}
}

void					set_format(t_arg *new, va_list ap)
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
	if (new->isl && (is_char(new) || is_str(new)))
		new->islower = 0;
	if (is_num(new))
	{
		switch_num(new, ap);
		format_num(new);
	}
	else if (is_char(new) || is_string(new))
		get_chars(new, ap);
	else if (new->arg == '%')
		format_htg(new);
}
