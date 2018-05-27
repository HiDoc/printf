/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:47:13 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/14 11:07:12 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoabase(long long n, int baseto, char *basefrom)
{
	if (n < 0 && baseto != 10)
		return (ft_ulltoabase(ULLONG_MAX + n + 1, baseto, basefrom));
	else
		return (ft_ulltoabase(n, baseto, basefrom));
}
