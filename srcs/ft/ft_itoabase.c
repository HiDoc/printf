/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:51:22 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/14 10:51:46 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoabase(int n, int baseto, char *basefrom)
{
	if (n < 0 && baseto != 10)
		return (ft_utoabase(UINT_MAX + n + 1, baseto, basefrom));
	else
		return (ft_utoabase(n, baseto, basefrom));
}
