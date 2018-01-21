/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:03:33 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/21 17:22:45 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			set_attribute(t_args *arg)
{
	int		count;
	char	c;

	count = 0;
	c = '.';
	if (arg->line && arg->line[count])
		while (arg->line[count] && (ft_isargument(c)
		|| ft_isdigit(c) || c == '.' || ft_isflag(c)))
		{
			c = arg->line[count];
			if (ft_isargument(c))
			{
				arg->attribut = c;
				return (count);
			}
			count++;
		}
	return (-1);
}

char		*set_argument(t_args *arg, va_list ap)
{
	return (char *)ft_switch(arg->attribut,'l', ap);
}

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
