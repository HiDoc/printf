/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:36:18 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/25 16:01:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	count;
	size_t	len;

	len = ft_strlen(s1);
	count = 0;
	while (count < n && s2[count])
	{
		s1[count + len] = s2[count];
		count++;
	}
	s1[count + len] = '\0';
	return (s1);
}
