/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:15:10 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 18:22:50 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_w(char const *s, char c)
{
	int		words;
	size_t	count;
	size_t	len;

	if (s == NULL)
		return (-1);
	len = ft_strlen(s);
	words = 0;
	count = 0;
	while (len > count)
	{
		if (s[count] != '\0' && s[count] != c)
			words++;
		while (len > count && (char)s[count] != c)
			count++;
		while (len > count && (char)s[count] == c)
			count++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wcount;
	size_t	start;
	size_t	len;

	wcount = 0;
	start = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (n_w(s, c) + 1))) == NULL)
		return (NULL);
	while (wcount < n_w(s, c) && s[start] != '\0')
	{
		len = 0;
		if (s[start] != '\0' && s[start] != c)
		{
			while (s[start + len] != '\0' && s[start + len] != c)
				len++;
			tab[wcount] = ft_strsub(s, start, len);
			start += len;
			wcount++;
		}
		while (s[start] && s[start] == c)
			start++;
	}
	tab[wcount] = 0;
	return (tab);
}
