/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:45:18 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/22 15:05:58 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(unsigned long n, int c)
{
	return ((n != 0 ? ft_getlen(n / 10, c + 1) : c));
}

char			*ft_uitoa(unsigned long n)
{
	char	*nbr;
	int		count;

	count = ft_getlen(n, -1);
	if (n == 0)
		return (ft_strdup("0"));
	if ((nbr = (char *)malloc((sizeof(char) * (count + 1)))) == NULL)
		return (NULL);
	nbr[count] = '\0';
	while (count >= 0)
	{
		nbr[count] = (n % 10) + '0';
		count--;
		n /= 10;
	}
	return (nbr);
}
