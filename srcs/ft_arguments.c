/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:03:33 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/12 14:02:37 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_isargument(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%'
			? c : 0);
}

char	*ft_switch(char *line, char c, va_list ap)
{
	char	swi;
	char	*tmp;

	if (!(swi = ft_isargument(c)))
		return (line);
	else if (swi == 's' || swi == 'S')
		tmp =  va_arg(ap, const char *);
	else if (swi == 'p')
		tmp = (void *);
	else if (swi == 'e' || swi == 'E')
		tmp = ft_itoa(va_arg(ap, int));
	else if (swi == 'o' || swi == 'O')
		tmp = va_arg(ap, unsigned int);
	else if (swi == 'd' || swi == 'i')
		tmp = ft_itoa(ap, int);
	else if (swi == 'g' || swi == 'G')
		tmp = va_arg(ap, const char *);
	else if (swi == 'u' || swi == 'U')
		tmp = va_arg(ap, const char *);
}
