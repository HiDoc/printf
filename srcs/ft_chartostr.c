/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:22:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/20 13:26:26 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chartostr(char c)
{
	char	*str;
	
	str = NULL;
	if ((str = (char *)malloc(sizeof(char) + 1)) == NULL)
		return (NULL);
	else
	{
		str[0] = c;
		str[1] = '\0';	
	}
	return (str);
}	
