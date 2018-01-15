/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:34:12 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/12 18:35:02 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	count;
	size_t	len;

	len = ft_strlen(dst);
	count = 0;
	if (size < len)
		return (ft_strlen(src) + size);
	while (size - len > count + 1 && size > count + 1 && src[count])
	{
		dst[count + len] = src[count];
		count++;
	}
	dst[count + len] = '\0';
	return (ft_strlen(src) + len);
}
