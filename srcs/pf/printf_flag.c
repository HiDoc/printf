/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:11:03 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/27 19:07:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_hexa(t_arg *new)
{
	return (new->arg == 'x' || new->arg == 'X' || new->arg == 'p');
}

int		is_octal(t_arg *new)
{
	return (new->arg == 'o' || new->arg == 'O');
}

int		is_string(t_arg *new)
{
	return (new->arg == 's' || new->arg == 'S');
}

int		is_char(t_arg *new)
{
	return (new->arg == 'c' || new->arg == 'C');
}

int		is_unsign(t_arg *new)
{
	return (new->arg == 'u' || new->arg == 'U');
}
