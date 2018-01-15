/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:29:43 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/12 17:22:02 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (s[count])
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	return (c == 0 ? (char *)&s[ft_strlen(s)] : NULL);
}
