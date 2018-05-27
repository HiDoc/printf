/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:27:59 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 11:18:50 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	char	*pdst;
	char	*psrc;
	size_t	count;

	count = 0;
	psrc = (char *)src;
	pdst = (char *)dst;
	while (count < n && (unsigned char)psrc[count] != (unsigned char)c)
	{
		pdst[count] = psrc[count];
		count++;
	}
	if (count == n)
		return (NULL);
	else
	{
		pdst[count] = psrc[count];
		return (&pdst[count + 1]);
	}
}
