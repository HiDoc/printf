/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:31:19 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/22 17:10:39 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		ft_isargument(char flag)
{
	return (flag == 's' || flag == 'S' || flag == 'p' || flag == 'd' || flag == 'D' ||
			flag == 'i' || flag == 'o' || flag == 'O' || flag == 'u' || flag == 'U' ||
			flag == 'x' || flag == 'X' || flag == 'c' || flag == 'C' ? flag : 0);
}

static int	ft_isnumber(char flag)
{
	return (ft_strchri("diouxDIOUX", flag) > -1);
}

static char	*ft_switch_long(char *tmp, char flag, va_list ap)
{
	long long	num;

	if (flag == 'u' || flag == 'U')
		return ((tmp = ft_uitoa(va_arg(ap, unsigned long))));
	else 
		num = va_arg(ap, long);
	if (flag == 'o' || flag == 'O')
		tmp = ft_ltoabase(num, 8, "01234567");
	else if (flag == 'x' || flag == 'X')
		tmp = ft_ltoabase(num, 16, flag == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	else
		tmp = ft_ltoa(num);
	return (tmp);
}

static char	*ft_switch2(char *tmp, char flag, va_list ap, int ish)
{
	int		e;
	int		num;

	num = 0;
	if (ft_isnumber(flag) && !(flag == 'u' || flag == 'U'))
		num = va_arg(ap, int);
	if (ish > -1)
		num = ish == 0 ? (signed char)num : (short)num;
	if (flag == 's' || flag == 'S')
		tmp = ft_strdup2((char *)va_arg(ap, char *));
	else if (flag == 'p')
		tmp = ft_itoa(va_arg(ap, int));
	else if (flag == 'e' || flag == 'E')
		tmp = ft_itoa(va_arg(ap, int));
	else if (flag == 'c' || flag == 'C')
	{
		e = va_arg(ap, int);
		tmp = ft_chartostr((char)e);
	}
	else if (flag == 'o' || flag == 'O')
		tmp = ft_itoabase(num, 8, "01234567");
	else if (flag == 'd' || flag == 'D')
		tmp = ft_itoa(num);
	else if (flag == 'i' || flag == 'I')
		tmp = ft_itoa(num);
	else if (flag == 'g' || flag == 'g')
		tmp = ft_strdup((char *)va_arg(ap, const char *));
	else if (flag == 'u' || flag == 'U')
		tmp = ish == -1  || flag != 'U' ? ft_uitoa(va_arg(ap, unsigned int)) : ft_uitoa(va_arg(ap, unsigned long));
	else if (flag == 'x' || flag == 'X')
		tmp = ft_itoabase(num, 16, flag == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	return (tmp);
}

const char			*ft_switch(char *str, int index, va_list ap)
{
	char		*tmp;
	char		flag;
	int			islong;
	int			isj;
	int			ish;
 
	ish = (ft_strnstr(str, "hh", index)) ? 0 : ft_strnchri(str, 'h', index);	
	islong = (ft_strnstr(str, "ll", index)) ? 0 : ft_strnchri(str, 'l', index);	
	isj = ft_strnchri(str, 'j', index);
	flag = str[index];
	tmp = NULL;
	if ((islong > -1 || isj > -1) && ft_isnumber(flag))
		tmp = ft_switch_long(tmp, flag, ap);
	else
		tmp = ft_switch2(tmp, flag, ap, ish);
	if (tmp == NULL)
		tmp = ft_strdup("(null)");
	return ((const char*)tmp);
}
