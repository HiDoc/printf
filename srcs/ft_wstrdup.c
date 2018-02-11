/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:46:14 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/11 13:45:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>
wchar_t	*ft_wstrdup(const wchar_t *s1)
{
	int		len;
	wchar_t	*dup;
	int		count;

	count = 0;
	if (s1 == NULL)
		return (NULL);
	len = ft_wcslen(s1);
	if ((dup = (wchar_t *)malloc(((sizeof(wchar_t) * len) + 1))) == NULL)
		return (NULL);
	while (count < len)
	{
		dup[count] = s1[count];
		count++;
	}
	dup[count] = '\0';
	return (dup);
}
