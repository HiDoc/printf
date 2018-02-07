/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:48:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/07 15:55:42 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_char(t_arg *new)
{
	char	*tmp;

	if (!new->islower || new->isl)
	{
		if (new->char0 > 0xFFFF)
			new->field--;
		if (new->char0 > 0x7FF)
			new->field--;
		if (new->char0 > 0xFF)
			new->field--;
	}
	if (new->field > 1)
	{
		tmp = ft_strnew(new->field - 1);
		ft_strset(tmp, new->is0 ? '0' : ' ', new->field - 1);
		if (new->format && new->islower && !new->isl)
			switch_minus(tmp, new);
		else if (!new->islower || new->isl)
			new->hformat = tmp;
		else
			new->format = tmp;
	}
}
