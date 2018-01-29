/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:16:28 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/29 12:42:19 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_str(char flag)
{
	return (ft_strchri("sScC", flag) > -1);
}

int		is_num(char flag)
{
	return (ft_strchri("diouxDIOUX", flag) > -1);
}

int		is_arg(char c)
{
	return (is_str(c) || is_num(c));
}
