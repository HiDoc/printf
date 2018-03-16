/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:07:45 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/16 16:28:42 by fmadura          ###   ########.fr       */
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
	ft_bzero(new, size + 1);
	return (new);
}
