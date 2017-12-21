/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:03:33 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 12:55:53 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		set_argument(t_args *arg, va_list ap)
{
	if (ft_isargument(arg->attribut))
		arg->argument = (char *)ft_switch(arg->attribut, ap);
}

char		ft_isargument(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%'
			? c : 0);
}

const char	*ft_switch(char c, va_list ap)
{
	const char	*tmp;

	tmp = NULL;
	if (c == 's' || c == 'S')
		tmp =  va_arg(ap, const char *);
	else if (c == 'p')
		tmp = ft_itoa(va_arg(ap, int));
	else if (c == 'e' || c == 'E')
		tmp = ft_itoa(va_arg(ap, int));
	else if (c == 'o' || c == 'O')
		tmp = ft_itoa(va_arg(ap, unsigned int));
	else if (c == 'd' || c == 'i')
		tmp = ft_itoa(va_arg(ap, int));
	else if (c == 'g' || c == 'G')
		tmp = va_arg(ap, const char *);
	else if (c == 'u' || c == 'U')
		tmp = va_arg(ap, const char *);
	return (tmp);
}
