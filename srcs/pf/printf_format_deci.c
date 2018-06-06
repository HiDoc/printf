/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_deci.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:50:26 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/05 14:15:16 by fmadura          ###   ########.fr       */
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
		ft_strset(tmp, ('0'), new->preci - len);
		new->format = ft_strdjoin(tmp, new->format);
	}
	if (first == '-' || first == '+')
		new->format[0] = first;	
}

static void	format_num_field(t_arg *new, int diff, int zero)
{
	char	*tmp;

	(void)zero;
	if (diff > 0)
	{
		tmp = ft_strnew(diff);
		ft_strset(tmp, (new->hpreci || new->isz ? ' ' : '0'), diff);
		switch_minus(tmp, new);
	}
}

void		format_deci(t_arg *new, va_list ap)
{
	int		len;
	int		zero;

	(void)ap;
	zero = 0;
	len = (int)ft_strlen(new->format);
	if (len == 1 && new->format[0] == '0' && new->hpreci && !new->preci)
	{
		zero = 1;
		free(new->format);
		new->format = ft_strdup(!zero || !new->isplus ? "" : "+");
	}
	else
		format_num_precision(new, len);
	len = new->format ? (int)ft_strlen(new->format) : 0;
	format_num_field(new, new->field - len, zero);
	if (new->ispace && !new->is0 && new->format[0] != ' ' 
		&& (new->preci == 0 || !new->hpreci))
		new->format = ft_strrjoin(" ", new->format);
	if (new->ispace && new->is0)
		new->format[0] = ' ';
}
