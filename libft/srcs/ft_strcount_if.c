/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:04:20 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/26 16:14:41 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcount_if(char *s, int (f)(int))
{
	int	count;
	int ret;

	count = 0;
	ret = 0;
	while (s[count])
	{
		if (f((int)s[count]))
			ret++;
		count++;
	}
	return (ret);
}
