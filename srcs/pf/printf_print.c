/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:51:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/28 11:04:38 by fmadura          ###   ########.fr       */
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

static int	print_check_next(t_arg *arg, size_t len, char *str)
{
	if (arg->error == 0)
	{
		if (arg->next == NULL)
			len += print_buffer(str, 1);
		else if ((!is_str(arg->next) && !arg->next->islower) || checkwstr(arg))
			len += print_buffer(str, 1);
		else if (!is_char(arg->next) || checkwchar(arg->next->char0))
			len += print_buffer(str, 1);
		return (len);
	}
	return (-1);
}

static int	print_error(t_arg *arg)
{
	if (arg->hformat)
	{
		free(arg->hformat);
		arg->hformat = NULL;
	}
	if (arg->format)
	{
		free(arg->format);
		arg->format = NULL;
	}
	return (-1);
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
					return (print_error(arg));
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
