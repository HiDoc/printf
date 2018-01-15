/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:10:12 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/13 17:18:30 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		count;
	char	*newstr;

	if (s == NULL || f == NULL)
		return (NULL);
	count = 0;
	if ((newstr = (char *)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[count])
	{
		newstr[count] = f(s[count]);
		count++;
	}
	newstr[count] = s[count];
	return (newstr);
}
