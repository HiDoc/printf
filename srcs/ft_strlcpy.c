/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:17:47 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/07 15:51:28 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	count;

	s = (char *)src;
	count = 0;
	if (!src || !size)
		return (0);
	while (src[count] && count < size)
	{
		dst[count] = src[count];
		count++;
	}
	return (count);
}
