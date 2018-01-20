/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:59:54 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/20 14:02:21 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup2(const char *s1)
{
	int		len;
	char	*dup;
	int		count;

	count = 0;
	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if ((dup = (char*)malloc(((sizeof(char) * len) + 1))) == NULL)
		return (NULL);
	while (count < len)
	{
		dup[count] = s1[count];
		count++;
	}
	dup[count] = s1[count];
	return (dup);
}
