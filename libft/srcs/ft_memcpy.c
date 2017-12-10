/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:25:17 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 17:21:34 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*src1;
	char	*dst1;
	size_t	count;

	count = 0;
	src1 = (char *)src;
	dst1 = (char *)dst;
	while (count < n)
	{
		dst1[count] = src1[count];
		count++;
	}
	return (dst1);
}
