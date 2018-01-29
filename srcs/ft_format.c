/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/29 17:52:05 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		get_format(t_arg *new, va_list ap)
{
	long long	num;
	int 		base;
	int			sign;

	sign = 0;
	num = 0;
	base = 10;
	if (new->arg == 'u')
		sign = 4;
	if (new->arg == 'U')
		sign = 5;
	if (is_num(new->arg))
	{
		if (ft_strchri("dDiI", new->arg) > -1 || new->isz)
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
			if ((new->isl == 2 || new->isj))
				num = va_arg(ap, unsigned long long);
			else if (new->arg == 'U' || new->isl == 1)
				num = va_arg(ap, unsigned long);
			else
				num = va_arg(ap, unsigned int);
		}
		if (ft_strchri("oOxX", new->arg) > -1)
			base = ((new->arg) == 'o' || (new->arg) == 'O' ? 8 : 16);
		if (new->ish == 1 && !sign)
			num = (short)num;
		if (new->ish == 2 && !sign)
		{
			sign = 1;
			num = (signed char)num;
		}
		new->format = ft_ltoabase(num, base,
				new->islower ? "0123456789abcdef" : "0123456789ABCDEF", sign);
	}
	else if (is_str(new->arg))
	{
		if (new->arg == 'c' || new->arg == 'C')
			new->char0 = va_arg(ap, int);
		else
		{
			new->format = ft_strdup2(va_arg(ap, char *));
			if (new->format == NULL)
				new->format = ft_strdup("(null)");
		}
	}
}

static void format_str(t_arg *new)
{
	char	*tmp;
	int		len;

	len = ((new->format != NULL) ? ft_strlen(new->format) : 0);
	if (new->preci > 0 && new->preci < len && new->format[0])
	{	
		tmp = ft_strsub(new->format, 0, new->preci);
		free(new->format);
		new->format = ft_strdup(tmp);
		free(tmp);
		len = (int)ft_strlen(new->format);
	}
	if (new->field - len > 0)
	{
		tmp = ft_strnew(new->field - len);
		ft_strset(tmp, ' ', new->field - len);
		if (new->ismins)
			new->format = ft_strdjoin(new->format, tmp);
		else
			new->format = ft_strdjoin(tmp, new->format);
	}
}

void static	format_num_precision(t_arg *new, int len)
{
	char	*tmp;

	if (new->format && new->format[0] == '0' && !(new->preci) && new->hpreci)
	{
		free(new->format);
		new->format = ft_strdup("");
	}
	else if (ft_strchri("xX", new->arg) > -1 && new->ishtg && new->format[0] != '0')
		new->format = ft_strrjoin((new->arg == 'x' ? "0x" : "0X"), new->format);
	if (ft_strchri("oO", new->arg) > -1 && (new->ishtg) && new->format[0] != '0')
		new->format = ft_strrjoin(("0"), new->format);
	if (ft_strchri("diDI", new->arg) > -1 && (new->isplus) && new->format[0] != '-')
		new->format = ft_strrjoin("+", new->format);
	if (new->preci > 0 && new->preci > len && ft_strchri("dDiIoOuU", new->arg) > -1)
	{
		tmp = ft_strnew(new->preci - len + (new->format[0] == '-'));
		ft_strset(tmp, '0', new->preci - len + (new->format[0] == '-'));
		if (new->format[0] == '-' || new->format[0] == '+')
		{
			tmp[0] = new->format[0];
			new->format[0] = '0';
		}
		new->format = ft_strdjoin(tmp, new->format);
	}
}

void static	format_num_field(t_arg *new, int diff)
{
	char	*tmp;

	if (diff > 0)
		tmp = ft_strnew(diff);
	if (!(new->ismins) && new->is0 && diff > 0)
	{
		ft_strset(tmp, (new->preci > 0 ? ' ' : '0'), diff);
		if (ft_strchri("xX", new->arg) > -1 && new->ishtg)
		{
			new->format[1] = '0';
			tmp[1] = new->arg == 'x' ? 'x' : 'X';
		}
		else if (new->format[0] == '-' || new->format[0] == '+')
		{
			tmp[0] = new->format[0];
			new->format[0] = '0';
		}
		new->format = ft_strdjoin(tmp, new->format);
	}
	else if (diff > 0)
	{	
		ft_strset(tmp, ' ', diff);
		new->format =  ((new->ismins) ? ft_strdjoin(new->format, tmp) :
				ft_strdjoin(tmp, new->format));
	}
}
void static	format_char(t_arg *new)
{
	char	*tmp;

	if (new->field > 1)
	{
		tmp = ft_strnew(new->field - 1);
		ft_strset(tmp, ' ', new->field - 1);
		if (new->format)
		{
			if (new->ismins)
				new->format = ft_strdjoin(new->format, tmp);
			else
				new->format = ft_strdjoin(tmp, new->format);
		}
		else
			new->format = tmp;
	}
}

void		set_format(t_arg *new)
{
	int		len;
	int		diff;

	len = 0;
	if (is_num(new->arg))
	{
		len = (int)ft_strlen(new->format);
		format_num_precision(new, len);
		len = (int)ft_strlen(new->format);
		diff = new->field - len;
		format_num_field(new, diff);
		if (new->arg == 'd' && new->ispace && ft_isdigit(new->format[0]))
			new->format = ft_strrjoin(" ", new->format);
	}
	else if (ft_strchri("sS", new->arg) > -1)
		format_str(new);
	else
		format_char(new);
	if (new->format)
		new->length = ft_strlen(new->format);
}
static int	lolprint(char *str, size_t len)
{
	char	buffer[11];

	return (write(1, str, len));
}

int		join_args(t_arg *first)
{
	size_t	len;
	int		percent;

	percent = 0;
	len = 0;
	while (first)
	{
		if (first->arg == '%')
			percent++;
		if (first->arg == 'c' || first->arg == 'C')
		{
			if (first->field > 1)
			{
				if (first->ismins)
					ft_putchar(first->char0);
				ft_putstr(first->format);
				if (!first->ismins)
					ft_putchar(first->char0);
			}
			else
				ft_putchar(first->char0);
			if (first->format && first->field == 0)
				ft_putstr(first->format);
			if (first->format)
				len += ft_strlen(first->format);
			len++;
		}
		else
		{
		   	if (percent % 2 != 0 || first->arg != '%')
				lolprint(first->format, first->length);
			else if (first->format[0] && first->format[1])
				ft_putstr(first->format);
			len += ft_strlen(first->format) - (percent % 2 == 0 && percent != 0);
		}
		first = first->next;
	}
	return ((int)len);
}

int		ft_format(const char *format, va_list ap)
{
	char	**store;
	t_arg	*first;
	size_t 	len;

	if (ft_strchri((char *)format, '%') == -1)
	{
		len = ft_strlen(format);
		lolprint((char *)format, len);
		return (len);	
	}
	store = ft_strcut(format, '%');
	first = map_arg(store, ap);
	len = join_args(first);
	return (len);
}
