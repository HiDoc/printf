/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:43:41 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 17:13:49 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;

	count = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	else
		while (haystack[count] && len > count)
		{
			if (ft_strncmp(&haystack[count], needle, ft_strlen(needle)) == 0)
			{
				return (count + ft_strlen(needle) > len ? NULL :
						(char *)&haystack[count]);
			}
			count++;
		}
	return (NULL);
}
