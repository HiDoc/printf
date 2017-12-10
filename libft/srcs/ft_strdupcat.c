/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:53:30 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/25 16:09:47 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupcat(const char *s1, const char *s2)
{
	size_t	len;
	size_t	count;
	size_t	count2;
	char	*dupcat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((dupcat = ft_strnew(len)) == NULL)
		return (NULL);
	count = 0;
	count2 = 0;
	while (s1[count])
	{
		dupcat[count] = s1[count];
		count++;
	}
	while (s2[count2])
	{
		dupcat[count + count2] = s2[count2];
		count2++;
	}
	return (dupcat);
}
