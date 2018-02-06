/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:09:14 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/06 11:59:12 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int 	check_wchar(wchar_t w)
{
	if (MB_CUR_MAX == 1 && w > 255)
		return (-1);
	if (MB_CUR_MAX == 1 && w <= 255)
		return (ft_putchar(w));
	if ((w > 0x10FFFF) || w < 0 || (w > 0xd7ff && w < 0xe000))
		return (-1);
	return (0);	
}

int			ft_putwchar(wchar_t w)
{
	int wchar[4];
	int ret;

	if ((ret = check_wchar(w)) != 0)
		return (ret);
	wchar[0] = (w & 0x3F) | 0x80;
	wchar[1] = (w >> 6) | 0xC0;
	if (w > 0x07FF)
	{	
		wchar[1] &= 0xbf;
		wchar[2] = w >> 12 | ((w > 0xFFFF) ? 0x80 : 0xE0);
	}
	if (w > 0xFFFF)
	{
		wchar[2] &= 0xbf;
		wchar[3] = w >> 18 | 0xF0;
	}
	if (w > 0xFFFF)
		ret += write(1, &wchar[3], 1);
	if (w > 0x07FF)
		ret += write(1, &wchar[2], 1);
	ret += write(1, &wchar[1], 1);
	ret += write(1, &wchar[0], 1);
	return (ret);
}
