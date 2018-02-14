/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:52:53 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/14 11:06:18 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ltoabase(long n, int baseto, char *basefrom)
{
	if (n < 0 && baseto != 10)
		return (ft_ultoabase(ULONG_MAX + n + 1, baseto, basefrom));
	else
		return (ft_ultoabase(n, baseto, basefrom));
}
