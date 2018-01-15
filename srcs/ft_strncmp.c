/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:41:46 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 11:49:55 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;
	int		diff;

	diff = 0;
	count = 0;
	while ((s1[count] || s2[count]) && diff == 0 && count < n)
	{
		diff += ((unsigned char)s1[count]);
		diff -= ((unsigned char)s2[count]);
		count++;
	}
	return (diff);
}
