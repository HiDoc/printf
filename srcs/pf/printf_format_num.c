/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:43:56 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/30 20:11:55 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	format_num_setchar(t_arg *new, int len, char *tmp)
{
	int		minus;
	int		space;

	minus = (new->format && new->format[0] == '-') ? 1 : 0;
	space = (new->isplus == 1 || new->ispace == 0 || minus == 1 ? 0 : 1);
	if (new->preci > 0 && (new->preci + minus + space) > len && is_num(new))
	{
		tmp = ft_strnew(new->preci - len + minus + space);
		ft_strset(tmp, '0', new->preci - len + minus + space);
		if ((new->format[0] == '-' || new->format[0] == '+'))
		{
			tmp[0] = new->format[0];
			new->format[0] = '0';
		}
		if (is_hexa(new) && new->ishtg)
		{
			if (tmp[1])
				tmp[1] = new->islower ? 'x' : 'X';
			else
				new->format[0] = new->islower ? 'x' : 'X';
			new->format[1] = '0';
		}
		if (space == 1)
			tmp[0] = ' ';
		new->format = ft_strdjoin(tmp, new->format);
	}
}

static void	format_num_precision(t_arg *new, int len)
{
	char	*tmp;

	tmp = NULL;
	if (new->format && new->format[0] == '0' && !(new->preci) && new->hpreci)
	{
		free(new->format);
		new->format = ft_strdup(is_deci(new) && new->ispace ? " " : "");
	}
	else if (is_hexa(new) && new->ishtg && new->format[0] != '0')
		new->format = ft_strrjoin((new->arg == 'X' ? "0X" : "0x"), new->format);
	if (is_octal(new) && (new->ishtg) && new->format[0] != '0')
	{
		new->format = ft_strrjoin(("0"), new->format);
		new->preci--;
	}
	if (is_deci(new) && (new->isplus) && new->format[0] != '-')
		new->format = ft_strrjoin("+", new->format);
	format_num_setchar(new, len, tmp);
}

static void	format_num_field(t_arg *new, int diff)
{
	char	*tmp;

	if (diff > 0)
		tmp = ft_strnew(diff);
	if (!(new->ismins) && new->is0 && diff > 0)
	{
		ft_strset(tmp, (new->hpreci ? ' ' : '0'), diff);
		if (is_hexa(new) && new->ishtg && new->format[1] && tmp[1] != ' ')
		{
			new->format[1] = '0';
			tmp[1] = new->arg == 'x' ? 'x' : 'X';
		}
		else if ((new->format[0] == '-' || new->format[0] == '+')
				&& (tmp[0] != ' '))
		{
			tmp[0] = new->format[0];
			new->format[0] = '0';
		}
		new->format = ft_strdjoin(tmp, new->format);
	}
	else if (diff > 0)
	{
		ft_strset(tmp, ' ', diff);
		switch_minus(tmp, new);
	}
}

void		format_num(t_arg *new, va_list ap)
{
	int		len;

	switch_num(new, ap);
	if (new->arg != 'p')
	{
		len = (int)ft_strlen(new->format);
		format_num_precision(new, len);
		len = new->format ? (int)ft_strlen(new->format) : 0;
		format_num_field(new, new->field - len);
	}
	else
		format_ptr(new);
	if (is_deci(new) && new->ispace && ft_isdigit(new->format[0]))
	{
		if (new->format[1] && new->format[0] == '0')
			new->format[0] = ' ';
		else
			new->format = ft_strrjoin(" ", new->format);
	}
}
