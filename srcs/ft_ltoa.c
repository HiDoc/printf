/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:35:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/22 15:17:58 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(long long n, int c)
{
	return ((n != 0 ? ft_getlen(n / 10, c + 1) : c));
}

char			*ft_ltoa(long long n)
{
	char	*nbr;
	int		count;
	int		ispos;

	ispos = (n >= 0);
	count = ft_getlen(n, 0) - (n > 0);
	if ((nbr = (char *)malloc((sizeof(char) * (count + 1)))) == NULL)
		return (NULL);
	nbr[count] = '\0';
	while (count >= 0)
	{
		nbr[count] = ABS((n % 10)) + '0';
		count--;
		n /= 10;
	}
	if (!ispos)
		nbr[0] = '-';
	return (nbr);
}
