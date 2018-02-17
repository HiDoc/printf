/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_wchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:21:29 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/17 12:30:39 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			print_wchar(t_arg *arg)
{
	int		error;
	int		len;

	len = 0;
	error = 0;
	if (!(arg->field > 1 && (arg->format || arg->hformat)) || (arg->ismins))
		error = switch_wchar(arg->char0, !arg->islower);
	if (arg->islower)
		len += print_buffer(arg->format, 1);
	else if (error != -1)
		len += print_buffer(arg->hformat, 1);
	if (error != -1 && arg->next && is_char(arg) &&
			!arg->islower && checkwchar(arg->next->char0))
		len += print_buffer(arg->format, 1);
	else if (error != -1 && !arg->next && !arg->islower)
		len += print_buffer(arg->format, 1);
	if (arg->field > 1 && (arg->format || arg->hformat) && !arg->ismins)
		error = switch_wchar(arg->char0, !arg->islower);
	if (error == -1)
		return (-1);
	len += error;
	return (len);
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
	if (arg->format)
		len += print_buffer(arg->format, 1);
	return (len);
}
