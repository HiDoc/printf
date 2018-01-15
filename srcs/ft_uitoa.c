/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:45:18 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 15:01:34 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(int n, int c)
{
	return ((n != 0 ? ft_getlen(n / 10, c + 1) : c));
}

char			*ft_uitoa(unsigned int n)
{
	char	*nbr;
	int		count;

	count = ft_getlen(n, -1);
	if (n == 0)
		return (ft_strdup("0"));
	if ((nbr = (char *)malloc((sizeof(char) * (count + 2)))) == NULL)
		return (NULL);
	nbr[count + 1] = '\0';
	while (count >= 0)
	{
		nbr[count] = (n % 10) + '0';
		count--;
		n /= 10;
	}
	return (nbr);
}