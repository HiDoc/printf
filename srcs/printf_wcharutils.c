/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wcharutils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:10:25 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/19 10:44:38 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		sizewchar(wchar_t t)
{
	int		count;

	count = 1;
	if (t > 0xff)
		count++;
	if (t > 0x7ff)
		count++;
	if (t > 0xffff)
		count++;
	return (count);
}

int		sizewstr(wchar_t *str)
{
	size_t	len;
	size_t	count;

	count = 0;
	len = 0;
	while (str[count])
	{
		len += sizewchar(str[count]);
		count++;
	}
	return (len);
}

int		checkwchar(wchar_t w)
{
	if (MB_CUR_MAX == 1 && w > 255)
		return (0);
	if (MB_CUR_MAX == 1 && w <= 255)
		return (1);
	if ((w > 0x10FFFF) || w < 0 || (w > 0xd7ff && w < 0xe000))
		return (0);
	return (1);
}

int		checkwstr(t_arg *arg)
{
	int		count;
	wchar_t	*str;

	count = 0;
	if (arg == NULL || arg->wformat == NULL)
		return (0);
	str = arg->wformat;
	while (str[count] && (count < arg->preci || !arg->hpreci))
	{
		if (!checkwchar(str[count]))
			return (0);
		count++;
	}
	return (1);
}
