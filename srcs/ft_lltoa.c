/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:34:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/14 11:59:47 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(long long n, int c)
{
	return ((n != 0 ? ft_getlen(n / 10, c + 1) : c));
}

char			*ft_lltoa(long long n)
{
	char	*nbr;
	int		count;
	int		ispos;

	ispos = (n >= 0);
	count = ft_getlen(n, 0) - (n > 0);
	if ((nbr = (char *)malloc((sizeof(char) * (count + 2)))) == NULL)
		return (NULL);
	nbr[count + 1] = '\0';
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
