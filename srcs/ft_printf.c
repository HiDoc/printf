/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:17:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/15 12:49:07 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	*tmp;

	len = 0;
	if (format[0])
	{
		va_start(ap, format);
		tmp = ft_format(format, ap);
		len = ft_strlen(tmp);
		ft_putstr(tmp);
		free(tmp);
		va_end(ap);
	}
	return (len);
}
