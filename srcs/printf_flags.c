/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:00:12 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/21 13:01:23 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_deci(t_arg *new)
{
	return (ft_strchri("dDiI", new->arg) > -1);
}

int		is_str(t_arg *new)
{
	return (is_char(new) || is_string(new));
}

int		is_num(t_arg *new)
{
	return (ft_strchri("diouxDIOUXp", new->arg) > -1);
}

int		is_arg(t_arg *new)
{
	return (is_str(new) || is_num(new));
}

int		is_charg(char c)
{
	return (ft_strchri("diouxDIOUXsScCpfF", c) > -1);
}
