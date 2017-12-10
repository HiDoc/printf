/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/07 13:14:33 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_format(const char *str, va_list ap)
{
	int		count;
	char	*sub;
	char	*store;

	count = 0;
	while (str[count])
	{
		if (str[count] == '%')
		{
			sub = ft_strsub(str, 0, count);
			store = ft_strjoin(sub, (char *)va_arg(ap, const char *));
			ft_putendl(store);
		}
		count++;
	}
	return (ft_strdup(str));
}
