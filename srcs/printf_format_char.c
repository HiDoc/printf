/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:51:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/21 12:52:24 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	get_char(t_arg *new, va_list ap)
{
	new->char0 = va_arg(ap, int);
	if (!new->islower && !checkwchar(new->char0))
		new->error = 1;
	format_char(new);
}

static void	get_str(t_arg *new,va_list ap)
{
	if (!new->islower)
	{
		new->wformat = ft_wstrdup(va_arg(ap, wchar_t *));
		if (!(checkwstr(new)))
			new->error = 1;
		if (new->wformat == NULL)
			new->wformat = str_to_wstr("(null)");
	}
	else
	{
		new->format = ft_strdup2(va_arg(ap, char *));
		if (new->format == NULL)
			new->format = ft_strdup("(null)");
	}
	format_str(new);

}

void		switch_char(t_arg *new, va_list ap)
{
	if (is_char(new))
		get_char(new, ap);
	else
		get_str(new, ap);
}
