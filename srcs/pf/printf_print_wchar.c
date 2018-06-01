/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_wchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:21:29 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/01 13:41:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			switch_wchar(int c, int iswchar)
{
	if (iswchar && c > 127)
		return (ft_putwchar(c));
	else if (!iswchar || c > -1)
		return (ft_putchar(c));
	return (-1);
}

int			print_wchar(t_arg *arg)
{
	int		error;
	int		nexterror;
	int		len;

	len = 0;
	error = 0;
	nexterror = 0;
	if (arg->next && is_char(arg->next) && !arg->next->islower)
		nexterror = !(checkwchar(arg->next->char0));
	if (!arg->islower)
		error = !(checkwchar(arg->char0));
	if (!error)
	{
		if (arg->hformat && !arg->ismins)
			len += print_buffer(arg->hformat, 1);
		error = switch_wchar(arg->char0, !arg->islower);
		if (arg->hformat && arg->ismins)
			len += print_buffer(arg->hformat, 1);
		if (arg->format && !nexterror)
			len += print_buffer(arg->format, 1);
	}
	else
		return (free_error(arg));
	return ((error == -1 ? free_error(arg) : len + error));
}

static int	iter_print(t_arg *arg, int count, int len, int count2)
{
	wchar_t	iter;

	iter = arg->wformat[count];
	while (iter && (count2 < arg->preci || !arg->hpreci))
	{
		if (count2 + sizewchar(iter) <= arg->preci || !arg->preci)
			len += switch_wchar(iter, 1);
		else if (MB_CUR_MAX == 1)
		{
			count2 += switch_wchar(iter, 0);
			len++;
		}
		count2 += sizewchar(iter);
		count++;
		iter = arg->wformat[count];
	}
	return (len);
}

int			print_bigstr(t_arg *arg)
{
	int		len;
	int		size;

	len = 0;
	size = (int)sizewstr(arg->wformat);
	if (arg->field && arg->field - size > 0 && arg->hformat && !arg->ismins)
		len += print_buffer(arg->hformat, 1);
	len = iter_print(arg, 0, len, 0);
	if (arg->field - size > 0 && arg->hformat && arg->ismins)
		len += print_buffer(arg->hformat, 1);
	return (len);
}
