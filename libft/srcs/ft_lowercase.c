/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:42:46 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 17:46:15 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lowercase(char *s)
{
	size_t	count;

	count = 0;
	if (s != NULL)
		while (s[count])
		{
			s[count] = ft_tolower(s[count]);
			count++;
		}
}
