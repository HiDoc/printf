/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:44:23 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 17:46:06 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_capitalize(char *s)
{
	size_t	count;

	count = 0;
	if (s != NULL)
		while (s[count])
		{
			s[count] = ft_toupper(s[count]);
			count++;
		}
}
