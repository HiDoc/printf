/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:09:12 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/13 13:29:10 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		count;

	if (s == NULL || f == NULL)
		return ;
	count = 0;
	while (s[count])
	{
		f(&s[count]);
		count++;
	}
}
