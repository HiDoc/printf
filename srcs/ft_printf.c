/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:17:37 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/12 09:39:01 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char* format, ...)
{
	va_list		ap;

	va_start(ap, format);
	ft_putstr(ft_format(format, ap));
	va_end(ap);
	return (1);
}
