/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:04:42 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 17:06:13 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strset(char *str, char c, size_t size)
{
	int count;

	count = 0;
	while (count < (int)size)
	{
		str[count] = c;
		count++;
	}
	return (str);
}
