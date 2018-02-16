/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:51:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/16 16:07:58 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			print_buffer(char *str, int freestr)
{
	char	buffer[SPEED];
	size_t	len;
	size_t	count;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		count = 0;
		ft_bzero(buffer, SPEED);
		while (count < len)
		{
			ft_bzero(buffer, count);
			write(1, buffer, ft_strlcpy(buffer, &str[count], SPEED - 1));
			count += SPEED - 1;
		}
		if (freestr && str)
		{
			free(str);
			str = NULL;
		}
	}
	return ((int)len);
}

static int	print_wchar(t_arg *arg)
{
	int error;
	int len;

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

static int	print_bigstr(t_arg *arg)
{
	int count;
	int count2;
	int len;

	len = 0;
	count = 0;
	count2 = 0;
	if (arg->field && arg->field - (int)sizewstr(arg->wformat) > 0 &&
			arg->hformat && !arg->ismins)
		len += print_buffer(arg->hformat, 1);
	while (arg->wformat[count] && (count2 < arg->preci || !arg->hpreci))
	{
		if (count2 + sizewchar(arg->wformat[count]) <= arg->preci || !arg->preci)
			len += switch_wchar(arg->wformat[count], 1);
		else if (MB_CUR_MAX == 1)
		{
			count2 += switch_wchar(arg->wformat[count], 0);
			len++;
		}
		count2 += sizewchar(arg->wformat[count]);
		count++;
	}
	if (arg->field - (int)sizewstr(arg->wformat) > 0 &&
			arg->hformat && arg->ismins)
		len += print_buffer(arg->hformat, 1);
	if (arg->format)
		len += print_buffer(arg->format, 1);
	return (len);
}

static int	print_check_next(t_arg *arg, size_t len, char *str)
{
	if (arg->next == NULL)
		len += print_buffer(str, 1);
	else if	((!is_str(arg->next) && !arg->next->islower) || checkwstr(arg))
		len += print_buffer(str, 1);
	else if	(!is_char(arg->next) || checkwchar(arg->next->char0))
		len += print_buffer(str, 1);
	return (len);
}

int			print_args(t_arg *arg, size_t len, int percent, int error)
{
	while (arg)
	{
		percent += (arg->arg == '%');
		if (is_char(arg))
		{
			if ((error = print_wchar(arg)) == -1)
				return (-1);
			len += error;
		}
		else
		{
			if (is_str(arg) && !arg->islower)
			{
				if (!checkwstr(arg))
					return (-1);
				len += print_bigstr(arg);
			}
			else if (percent % 2 != 0 || arg->arg != '%')
				len = print_check_next(arg, len, arg->format);
			else
				len = print_check_next(arg, len, arg->hformat);
		}
		arg = arg->next;
	}
	return ((int)len);
}
