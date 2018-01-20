/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:55:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/20 13:06:45 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int		count;
	int		ret;

	count = 0;
	ret = 0;
	if ((s[0]) && s[0] != c)
		ret++;
	while (s[count])
	{
		if (s[count] == c)
			ret++;
		count++;
	}
	return (ret);
}

char		**ft_strcut(char const *s, char c)
{
	char	**tab;
	size_t	start;
	size_t	len;
	int wcount;

	wcount = 0;
	start = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (words(s, c) + 1))) == NULL)
		return (NULL);
	while (wcount < words(s, c) && s[start] != '\0')
	{
		len = 0;
		if (s[start] == c)
			len++;
		while (s[start + len] != '\0' && s[start + len] != c)
			len++;
		tab[wcount] = ft_strsub(s, start, len);
		start += len;
		wcount++;
	}
	tab[wcount] = 0;
	return (tab);
}
