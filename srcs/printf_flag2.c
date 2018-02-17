/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:06:06 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/17 15:35:50 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_flag(char c)
{
	return (ft_strchri(" plhjzdiouxDIOUXsScCi.-+#%", c) > -1
			|| ft_isdigit(c));
}

int		is_flag_bonus(char c)
{
	return (ft_strchri("*eEfFgG", c) > - 1);
}
