/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:36:18 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/17 20:15:13 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	ft_printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a');
	printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a');
	return (0);
}
