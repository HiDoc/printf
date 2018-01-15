/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:55:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/15 17:04:47 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	words(char const *s, char c)
{
	int		count;
	int		ret;

	count = 0;
	ret = 0;
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

	wcount = 0;
	start = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (words(s, c) + 1))) == NULL)
		return (NULL);
	while (wcount < n_w(s, c) && s[start] != '\0')
	{
		len = 0;
		while (s[start + len] != '\0' && s[start + len] != c)
			len++;
		if (s[start] == c)
			len++;
		tab[wcount] = ft_strsub(s, start, len);
		start += len;
		wcount++;
	}
	tab[wcount] = 0;
	return (tab);
}
