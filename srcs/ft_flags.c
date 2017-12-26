/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:52:58 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/26 14:46:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_haveflag(char *str)
{
	int count;
	int ret;

	count = 0;
	ret = 0;
	while (str[count])
	{
		if (ft_isflag(str[count]))
			ret += (int)str[count];
		count++;
	}
	return (ret);
}

char	ft_isflag(char c)
{
	return (c == '-' || c == '0' || c == '+');
}
