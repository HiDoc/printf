/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 12:39:15 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_format(const char *format, va_list ap)
{
	char	**store;
	int		count;
	t_args	*args;
	t_args	*start;

	count = 0;
	store = ft_strsplit(format, '%');
	if (store[count])
	{
		args = ft_new_arg(store[count]);
		start = args;
		count++;
	}
	while (store[count])
	{	
		args->next = ft_new_arg(store[count]);
		args = args->next;
		count++;
	}
	free(store);
	ft_map_args(start, ap);
	return (ft_join_arg(start));
}
