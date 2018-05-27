/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:39:29 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/17 12:07:09 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(unsigned long n, int c, int baseto)
{
	return ((n != 0 ? ft_getlen(n / baseto, c + 1, baseto) : c));
}

char		*ft_ultoabase(unsigned long n, int baseto, char *basefrom)
{
	char					*nbr;
	int						count;

	if (n == 0)
		return (ft_strdup("0"));
	count = ft_getlen(n, 0, baseto);
	if ((nbr = (char *)malloc((sizeof(char) * (count + 1)))) == NULL)
		return (NULL);
	nbr[count] = '\0';
	while (--count >= 0)
	{
		nbr[count] = basefrom[(n % baseto)];
		n /= baseto;
	}
	return (nbr);
}
