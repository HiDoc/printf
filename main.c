/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:28:44 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/20 11:42:49 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	main(void)
{
	char str[] = "%fd%d%e";
	char **tab = ft_strcut(str, '%');
	int count = 0;
	while (tab[count])
	{
		printf("count : %d, string : %s\n", count, tab[count]);
		count++;
	}
	ft_printf("%  %");
	return (0);
}
