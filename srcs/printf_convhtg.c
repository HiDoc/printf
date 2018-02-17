/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convhtg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:57:45 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/17 13:28:56 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_htg(t_arg *arg)
{
	char	*tmp;

	if (arg->field - 1 > 0)
	{
		tmp = ft_strnew(arg->field - 1);
		ft_strset(tmp, arg->is0 && !arg->ismins ? '0' : ' ', arg->field - 1);
		switch_minus(tmp, arg);
	}
}
