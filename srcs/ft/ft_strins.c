/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:14:22 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/22 13:34:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strins(char *from, char *ins, size_t index)
{
	char	*new;
	size_t	len;
	size_t	count;

	if (from == NULL || ins == NULL || index > (len = (int)ft_strlen(from)))
		return (NULL);
	count = ft_strlen(ins);
	len = count + len;
	new = ft_strnew(len);
	new = ft_strncpy(from, new, index);
	new = ft_strncpy(ins, &new[index], count);
	while (count + index < len)
	{
		new[count + index] = from[index];
		index++;
	}
	return (new);
}
