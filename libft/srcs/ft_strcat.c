/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:23:30 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/09 12:04:45 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int lens1;
	int lens2;
	int count;

	count = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	while (count < lens2)
	{
		s1[count + lens1] = s2[count];
		count++;
	}
	s1[count + lens1] = '\0';
	return (s1);
}
