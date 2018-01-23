/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:28:44 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/23 18:44:49 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	main(void)
{
	int count = 0;
	ft_printf("ft  : %#o\n", 0);
	printf("printf : %#o\n", 0);
	ft_printf("ft : %llo\n", (unsigned long long)-127);	
	printf("printf :%llo\n", (unsigned long long)-127);
	ft_printf("ft : %hho\n", (unsigned char)-12);
	printf("printf :%hho\n", (unsigned char)-12);
	return (0);
}
