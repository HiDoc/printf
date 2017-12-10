/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:07:45 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/13 17:44:23 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	count;

	count = 0;
	if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (count <= size + 1)
	{
		new[count] = '\0';
		count++;
	}
	return (new);
}
