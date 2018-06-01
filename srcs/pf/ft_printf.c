/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:17:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/01 14:16:46 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_format(const char *format, va_list ap)
{
	char	**store;
	t_arg	*first;
	size_t	len;

	len = 0;
	if (ft_strchri((char *)format, '%') == -1)
		return (print_buffer((char *)format, 0));
	store = ft_strcut(format, '%');
	first = map_arg(store, ap);
	if (!first->next && first->arg == '%')
	{
		len = (print_buffer(first->hformat, 1));
		if (first->format)
			free(first->format);
		free(first);
		return (len);
	}
	len = print_args(first, 0, 0, 0);
	free_list(first);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (format[0])
	{
		va_start(ap, format);
		len = ft_format(format, ap);
		va_end(ap);
	}
	return (len);
}
