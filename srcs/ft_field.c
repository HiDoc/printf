/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:00:37 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 10:56:02 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_get_field(char *str)
{
	int	index;
	int ret;

	index = ft_strchri(str, '.');
	ret = (index >= 0 ? ft_atoi(&str[index]) : (int)ft_strlen(str));
	return (ret);
}
