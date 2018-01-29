/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:28:44 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/29 17:16:00 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	main(void)
{
	ft_printf("hello %hho", UCHAR_MAX);
	printf("hello %d", UCHAR_MAX);
	return (0);
}
