/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:03:33 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/21 17:26:15 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		ft_isargument(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C'
			? c : 0);
}

const char	*ft_switch(char c, char size, va_list ap)
{
	const char		*tmp;
	int				e;

	tmp = NULL;
	if (c == 's' || c == 'S')
		tmp = ft_strdup2((char *)va_arg(ap, char *));
	else if (c == 'p')
		tmp = size == 'l' ? ft_itoa(va_arg(ap, int)) : ft_ltoa(va_arg(ap, long));
	else if (c == 'e' || c == 'E')
		tmp = ft_itoa(va_arg(ap, int));
	else if (c == 'c' || c == 'C')
	{
		e = va_arg(ap, int);
		if (e == 0)
			tmp = ft_strdup("^@");
		else
			tmp = ft_chartostr((char)e);
	}
	else if (c == 'o' || c == 'O')
		tmp = ft_itoabase(va_arg(ap, int), 8, "01234567");
	else if (c == 'd' || c == 'i')
		tmp = size != 'l' ? ft_itoa(va_arg(ap, int)) : ft_ltoa(va_arg(ap, long));
	else if (c == 'g' || c == 'G')
		tmp = ft_strdup((char *)va_arg(ap, const char *));
	else if (c == 'u' || c == 'U')
		tmp = ft_uitoa(va_arg(ap, unsigned int));
	else if (c == 'x')
		tmp = ft_itoabase(va_arg(ap, int), 16, "0123456789abcdef");
	else if (c == 'X')
		tmp = ft_itoabase(va_arg(ap, int), 16, "0123456789ABCDEF");
	if (tmp == NULL)
		tmp = ft_strdup("(null)");
	return (tmp);
}
