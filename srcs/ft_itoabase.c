/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:36:49 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/30 12:36:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(unsigned int n, int c, int baseto)
{
	return ((n != 0 ? ft_getlen(n / baseto, c + 1, baseto) : c));
}

char			*ft_itoabase(int n, int baseto, char *basetofrom)
{
	char			*nbr;
	int				count;
	int				ispos;
	unsigned int	uint;

	if (n == 0)
		return (ft_strdup("0"));
	ispos = (n >= 0 || baseto != 10);
	if (n < 0 && baseto != 10)
		uint = UINT_MAX + n + 1;
	else
		uint = n;
	count = ft_getlen(uint, 0, baseto) - (n > 0 && baseto == 10);
	if ((nbr = (char *)malloc((sizeof(char) * (count + 1)))) == NULL)
		return (NULL);
	nbr[count] = '\0';
	while (--count >= 0)
	{
		nbr[count] = basetofrom[ABS((uint % baseto))];
		uint /= baseto;
	}
	if (!ispos)
		nbr[0] = '-';
	return (nbr);
}
