/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:00:23 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/11 12:16:38 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	switch_minus(char *tmp, t_arg *new)
{
	if (new->ismins)
		new->format = ft_strdjoin(new->format, tmp);
	else
		new->format = ft_strdjoin(tmp, new->format);
}
