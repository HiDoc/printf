/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:50:49 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 18:52:30 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_pow(int num, int pow)
{
	unsigned long	ret;

	ret = 1;
	if (pow == 0)
		ret = 1;
	else if (num == 0 || pow < 0)
		ret = 0;
	else
		while (pow > 0)
		{
			ret *= num;
			pow--;
		}
	return (ret);
}
