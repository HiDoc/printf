/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:31:13 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/12 13:56:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int count;
	int diff;

	count = 0;
	diff = 0;
	while ((s1[count] || s2[count]) && diff == 0)
	{
		diff += ((unsigned char)s1[count]) - 0;
		diff -= ((unsigned char)s2[count]) - 0;
		count++;
	}
	return (diff);
}
