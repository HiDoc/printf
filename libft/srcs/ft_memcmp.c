/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:24:23 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/13 18:24:57 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			count;

	count = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (count < n)
	{
		if (ps1[count] != ps2[count])
			return (ps1[count] - ps2[count]);
		count++;
	}
	return (0);
}
