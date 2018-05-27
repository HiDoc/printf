/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:42:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/20 13:08:37 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strnchri(char *str, char c, int n)
{
	int count;

	count = 0;
	while (str[count] && count < n)
	{
		if (str[count] == c)
			return (count);
		count++;
	}
	return (-1);
}
