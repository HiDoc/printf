/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:56:29 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/22 10:50:23 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoispace(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

int			ft_atoi(const char *str)
{
	int				count;
	int				ispos;
	long			res;

	count = 0;
	ispos = 1;
	res = 0;
	while (str[count] && (ft_atoispace(str[count]) || str[count] == ' '))
		count++;
	if (str[count] && (str[count] == '-' || str[count] == '+'))
		ispos -= (str[count] == '-');
	count += (str[count] == '-' || str[count] == '+');
	while (str[count] && ft_isdigit(str[count]))
	{
		res = (res * 10) + (str[count] - 48);
		count++;
	}
	if (ispos ? res > 2147483647 : res > 2147483648)
		if (res > 9223372036854775807)
			return (ispos ? -1 : 0);
		else
			return ((int)res);
	else
		return ((int)res * (ispos ? 1 : -1));
}
