/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/06 17:06:47 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long int get_num(t_arg *new, va_list ap, int isunsign)
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
		if (new->isl == 2 || new->isz )
			num = va_arg(ap, unsigned long long);
		else if (new->isj)
			num = va_arg(ap, long long);
		else if (new->arg == 'U' || new->isl == 1)
			num = va_arg(ap, unsigned long);
		else
			num = va_arg(ap, unsigned int);
		if (num < 0)
			num = (unsigned long long)num;
	}
	return (num);
}

static void	get_decimal(t_arg *new, va_list ap)
{
	long long int	num;

	num = get_num(new, ap, 0);
	if (new->ish == 1)
		num = (short)num;
	if (new->ish == 2)
		num = (signed char)num;
	new->format = ft_ltoabase(num, 10, "0123456789", 0);
}

static void	get_unsigned(t_arg *new, va_list ap)
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

void		get_format(t_arg *new, va_list ap)
{
	long long	num;
	int 		base;
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
}

static void format_str(t_arg *new)
{
	char	*tmp;
	int		len;

	len = ((new->format != NULL) ? ft_strlen(new->format) : 0);
	if (new->hpreci && new->preci < len && new->format[0])
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
		switch_minus(tmp, new);
	}
}

void static	format_num_precision(t_arg *new, int len)
{
	char	*tmp;

	if (new->format && new->format[0] == '0' && !(new->preci) && new->hpreci)
	{
		free(new->format);
		new->format = ft_strdup(is_deci(new) && new->ispace ? " " : "");
	}
	else if ((is_hexa(new) && new->ishtg && new->format[0] != '0') || new->arg == 'p')
		new->format = ft_strrjoin((new->arg == 'X' ? "0X" : "0x"), new->format);
	if (is_octal(new) && (new->ishtg) && new->format[0] != '0')
	{
		new->format = ft_strrjoin(("0"), new->format);
		new->preci--;
	}
	if (is_deci(new) && (new->isplus) && new->format[0] != '-')
		new->format = ft_strrjoin("+", new->format);
	if (new->preci > 0 && new->preci > len && is_num(new))
	{
		tmp = ft_strnew(new->preci - len + (new->format[0] == '-'));
		ft_strset(tmp, '0', new->preci - len + (new->format[0] == '-'));
		if (new->format[0] == '-' || new->format[0] == '+')
		{
			tmp[0] = new->format[0];
			new->format[0] = '0';
		}
		if (is_hexa(new) && new->ishtg)
		{
			if (tmp[1])
				tmp[1] = new->islower ? 'x' : 'X';
			else
				new->format[0] = new->islower ?'x' : 'X';
			new->format[1] = '0';
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
		ft_strset(tmp, (new->hpreci ? ' ' : '0'), diff);
		if (is_hexa(new) && new->ishtg && new->format[1] && tmp[1] != ' ')
		{
			new->format[1] = '0';
			tmp[1] = new->arg == 'x' ? 'x' : 'X';
		}
		else if ((new->format[0] == '-' || new->format[0] == '+')
				&& (tmp[0] != ' ' || !new->isplus))
		{
			tmp[0] = new->format[0];
			new->format[0] = '0';
		}
		new->format = ft_strdjoin(tmp, new->format);
	}
	else if (diff > 0)
	{	
		ft_strset(tmp, ' ', diff);
		switch_minus(tmp, new);	
	}
}

void static	format_char(t_arg *new)
{
	char	*tmp;

	if (!new->islower || new->isl)
	{
		if (new->char0 > 0xFFFF)
			new->field--;
		if (new->char0 > 0x7FF)
			new->field--;
		if (new->char0 > 0xFF)
			new->field--;
	}
	if (new->field > 1)
	{
		tmp = ft_strnew(new->field - 1);
		ft_strset(tmp,new->is0 ? '0' : ' ', new->field - 1);
		if (new->format && new->islower && !new->isl)
			switch_minus(tmp, new);
		else if (!new->islower || new->isl)
			new->hformat = tmp;
		else
			new->format = tmp;
	}
}

void		set_format(t_arg *new)
{
	int		len;
	int		diff;

	len = 0;
	if (is_num(new))
	{
		len = (int)ft_strlen(new->format);
		format_num_precision(new, len);
		len = (int)ft_strlen(new->format);
		diff = new->field - len;
		format_num_field(new, diff);
		if (is_deci(new) && new->ispace && ft_isdigit(new->format[0]))
		{
			if (new->format[1] && new->format[0] == '0')
				new->format[0] = ' ';
			else
				new->format = ft_strrjoin(" ", new->format);
		}
	}
	else if (is_string(new))
		format_str(new);
	else
		format_char(new);
	if (new->format)
		new->length = ft_strlen(new->format);
}
#define SPEED 750
static int	lolprint(char *str, int freestr)
{
	char	buffer[SPEED];
	size_t	len;
	size_t	count;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		count = 0;
		ft_bzero(buffer, SPEED);
		while (count < len)
		{
			ft_bzero(buffer, count);
			write(1, buffer, ft_strlcpy(buffer, &str[count], SPEED - 1));
			count += SPEED - 1;
		}
		if (freestr && str)
			free(str);
	}
	return ((int)len);
}

static int checkchar(wchar_t w)
{
	if (MB_CUR_MAX == 1 && w > 255)
		return (0);
	if (MB_CUR_MAX == 1 && w <= 255)
		return (1);
	if ((w > 0x10FFFF) || w < 0 || (w > 0xd7ff && w < 0xe000))
		return (0);
	return (1);
}

static int sizewchar(wchar_t t)
{
	int count = 0;
	if (t > 0xff)
		count++;
	if (t > 0x7ff)
		count++;
	if (t > 0xffff)
		count++;
	if (t > 0xffffff)
		count++;

}

static int checkstr(t_arg *new)
{
	int count;
	wchar_t *str;

	str = new->wformat;
	count = 0;
	while (str[count] && (count < new->preci || !new->hpreci))
	{
		if (!checkchar(str[count]))
			return (0);
		count++;
	}
	return (1);
}

static int charlolol(int c, int iswchar)
{
	if (iswchar && c > 127)
		return (ft_putwchar(c));
	else if (!iswchar || c > -1)
		return (ft_putchar(c));
	return (-1);
}
static int charlol(t_arg *first)
{
	int error;
	int len;
	
	len = 0;
	error = 0;
	if (!(first->field > 1 && (first->format || first->hformat)) || (first->ismins))
		error = charlolol(first->char0, !first->islower || first->isl);
	if (first->islower && !first->isl)
		len += lolprint(first->format, 0);
	else 
		len += lolprint(first->hformat, 0);
	if (error != -1 && first->next && is_char(first) && (!first->islower || first->isl) && checkchar(first->next->char0))
		len += lolprint(first->format, 0);
	else if (error != -1 && !first->next && (!first->islower || first->isl))
		len += lolprint(first->format, 0);
	if (first->field > 1 && (first->format || first->hformat) && !first->ismins)
		error = charlolol(first->char0, !first->islower || first->isl);
	if (error == -1)
		return (-1);
	len += error;
	return (len);
}

int		join_args(t_arg *first)
{
	size_t	len;
	int		percent;
	int		error;

	error = 0;
	percent = 0;
	len = 0;
	while (first)
	{
		percent += (first->arg == '%');
		if (is_char(first))
		{
			if ((error = charlol(first)) == -1)
				return (-1);
			len += error;
		}
		else
		{
			if (is_str(first) && (!first->islower || first->isl))
			{
				if (!checkstr(first))
					return (-1);
				int count = 0;
				while (first->wformat[count] && (count < first->preci || !first->hpreci))
				{
					len += charlolol(first->wformat[count], 1);
					count++;
				}
			}
			else if (percent % 2 != 0 || first->arg != '%')
				len += lolprint(first->format, 1);
			else
				len += lolprint(first->hformat, 0);
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
		return (lolprint((char *)format, 0));
	store = ft_strcut(format, '%');
	first = map_arg(store, ap);
	if (!first->next && first->arg == '%')
		return (lolprint(first->hformat, 0));
	len = join_args(first);
	return (len);
}
