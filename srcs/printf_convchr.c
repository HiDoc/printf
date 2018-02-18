/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:48:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/18 11:56:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_char(t_arg *new)
{
	char	*tmp;

	if (!new->islower)
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
		new->hformat = tmp;
	}
}
