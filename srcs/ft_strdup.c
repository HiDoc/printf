/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:32:10 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/20 14:08:09 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;
	int		count;

	count = 0;
	len = ft_strlen(s1);
	if ((dup = (char *)malloc(((sizeof(char) * len) + 1))) == NULL)
		return (NULL);
	while (count < len)
	{
		dup[count] = s1[count];
		count++;
	}
	dup[count] = s1[count];
	return (dup);
}
