/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:03:33 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 17:16:21 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			set_attribute(t_args *arg, va_list ap)
{
	int		count;
	char	c;

	count = 0;
	c = '.';
	if (arg->line && arg->line[count])
		while (arg->line[count] && (ft_isargument(c) || ft_isdigit(c) 
					|| c == '.' || ft_isflag(c)))
		{
			c = arg->line[count];
			if (ft_isargument(c))
			{
				arg->attribut = c;
				arg->argument = (char *)ft_switch(c, ap);
				return (count);
			}
			count++;
		}
	return (-1);
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
	const char		*tmp;
	int				temp;
	unsigned int	uint;

	temp = 0;
	uint = 0;
	tmp = NULL;
	if (c == 's' || c == 'S')
		tmp = ft_strdup((char *)va_arg(ap, const char *));
	else if (c == 'p')
		tmp = ft_itoa(va_arg(ap, int));
	else if (c == 'e' || c == 'E')
		tmp = ft_itoa(va_arg(ap, int));
	else if (c == 'o' || c == 'O')
		tmp = ft_itoa((temp = va_arg(ap, unsigned int)));
	else if (c == 'd' || c == 'i')
		tmp = ft_itoa(va_arg(ap, int));
	else if (c == 'g' || c == 'G')
		tmp = ft_strdup((char *)va_arg(ap, const char *));
	else if (c == 'u' || c == 'U')
		tmp = ft_uitoa((uint = va_arg(ap, unsigned int)));
	return (tmp);
}
