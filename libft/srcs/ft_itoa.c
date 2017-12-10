/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:16:59 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/21 20:37:40 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(int n, int c)
{
	return ((n != 0 ? ft_getlen(n / 10, c + 1) : c));
}

char			*ft_itoa(int n)
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
