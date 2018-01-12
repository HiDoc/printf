/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:29:52 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/12 15:50:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(int n, int c, int base)
{
	return ((n != 0 ? ft_getlen(n / base, c + 1, base) : c));
}

static char		ft_getbase(int c)
{
	return (c < 10 ? c + '0' : c - 10 + 'A');
}

char			*ft_itoabase(int n, int base)
{
	char	*nbr;
	int		count;
	int		ispos;

	ispos = (n >= 0 || base != 10);
	if (n < 0 && base != 10)
		n = INT_MAX - n - 1;
	count = ft_getlen(n, 0, base) - (n > 0 && base == 10);
	if ((nbr = (char *)malloc((sizeof(char) * (count + 1)))) == NULL)
		return (NULL);
	nbr[count] = '\0';
	count--;
	while (count >= 0)
	{
		nbr[count] = ft_getbase(ABS((n % base)));
		count--;
		n /= base;
	}
	if (!ispos)
		nbr[0] = '-';
	return (nbr);
}
