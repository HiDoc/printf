/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:36:18 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/18 14:35:59 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <locale.h>
int		main(void)
{
int f = -42;
int a =	
	ft_printf("{%o}", f)
	+ ft_printf("{%ho}", f)
	+ ft_printf("{%hho}", f);

int b =
	printf("{%o}", f)
	+ printf("{%ho}", f)
	+ printf("{%hho}", f);
printf("%d %d", a, b);
	return (0);
}
