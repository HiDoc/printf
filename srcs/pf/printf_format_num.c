/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:43:56 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/07 20:45:15 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	format_num_precision(t_arg *new, int len)
{
	char	*tmp;
	char	first;

	(void)len;
	first = new->format ? new->format[0] : 0;
	tmp = NULL;
	if (new->isplus && first != '-')
		new->format = ft_strrjoin("+", new->format);
	first = new->format ? new->format[0] : 0;
	if (first == '-' || first == '+')
	{
		if (first == '-')
			new->preci++;
		new->format[0] = '0';
	}
	if (len < new->preci)
	{
		tmp = ft_strnew(new->preci - len);
		ft_strset(tmp, '0', new->preci - len);
		new->format = ft_strdjoin(tmp, new->format);
	}
	if (first == '-' || first == '+')
		new->format[0] = first;
}

static void	format_num_field(t_arg *new, int diff, int zero)
{
	char	*tmp;
	char	first;

	first = new->format[0];
	(void)zero;
	if (new->ismins && new->ispace)
		diff--;
	if (diff > 0)
	{
		tmp = ft_strnew(diff);
		ft_strset(tmp, !new->is0 || new->hpreci ? ' ' : '0', diff);
		if ((first == '+' || first == '-') && new->is0 && !new->hpreci)
		{
			new->format[0] = tmp[0];
			tmp[0] = first;
		}
		switch_minus(tmp, new);
	}
}

void		format_num(t_arg *new, va_list ap)
{
	int		len;
	int		zero;

	switch_num(new, ap);
	zero = 0;
	if (is_deci(new))
		format_deci(new, ap);
	else if (new->arg != 'p')
	{
		len = (int)ft_strlen(new->format);
		if (len == 1 && new->format[0] == '0')
		{
			zero = 1;
			if (new->hpreci && !new->preci)
			{
				free(new->format);
				new->format = ft_strdup("");
			}
		}
		format_num_precision(new, len);
		len = new->format ? (int)ft_strlen(new->format) : 0;
		format_num_field(new, new->field - len, zero);
	}
	else
		format_ptr(new);
}
