/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 10:36:11 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 11:04:05 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_args	*ft_new_arg(char *str)
{
	t_args *new;
	int count;

	count = 0;
	if ((new = (t_args *)malloc(sizeof(t_args))) == NULL)
		return NULL;
	while (!ft_isargument(str[count]))
		count++;
	if (count == (int)ft_strlen(str))
	{
		new->line = ft_strdup(str);
		new->flags = NULL;
		new->attribut = '0';
	}
	else
	{
		new->line = ft_strsub(str, count + 1, (int)ft_strlen(str));
		new->flags = ft_strsub(str, 0, count);
		new->attribut = str[count];
	}
	new->precision = -1;
	new->length = -1;
	return (new);
}
