/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:35:11 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/18 11:57:43 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	format_ptr_preci(t_arg *new)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(new->format);
	if (new->hpreci && new->preci && new->preci > (int)len)
	{
		tmp = ft_strnew(new->preci - len);
		ft_strset(tmp, '0', new->preci - len);
		new->format = ft_strdjoin(tmp, new->format);
		len = ft_strlen(new->format);
	}
	if (new->hpreci && !new->preci)
	{
		free(new->format);
		new->format = ft_strdup("0x");
	}
}

static void	format_ptr_field(t_arg *new)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(new->format);
	if (!new->hpreci || new->preci)
	{
		if ((size_t)new->field > len && new->field > 3)
		{
			len = new->field - len - 2;
			tmp = ft_strnew(len);
			ft_strset(tmp, new->is0 ? '0' : ' ', len);
			if (new->ismins || new->is0)
				switch_minus(tmp, new);
			new->format = ft_strrjoin("0x", new->format);
			if (!new->ismins && !new->is0)
				switch_minus(tmp, new);
		}
		else
			new->format = ft_strrjoin("0x", new->format);
	}
}

void		format_ptr(t_arg *new)
{
	format_ptr_preci(new);
	format_ptr_field(new);
}
