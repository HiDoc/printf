/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/12 12:56:07 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*join(char *s1, char *s2, int tab)
{
	char	*tmp;

	tmp = ft_strjoin((tab ? s1: &s1[1]), s2);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	s1 = ft_strdup(tmp);
	free(tmp);
	return (s1);
}

static char		*join_tab(char **tab)
{
	int		count;
	char 	*store;

	count = 0;
	store = NULL;
	if (tab[count])
	{
		store = ft_strdup(tab[0]);
		free(tab[0]);
		count++;
		while (tab[count])
		{
			store = join(store, tab[count], 1);
			free(tab[count]);
			count++;
		}
		free(tab);
	}
	return (store);
}

char			*ft_format(const char *format, va_list ap)
{
	char	**store;
	int		count;
	char	*tmp;

	count = 0;
	store = ft_strsplit(format, '%');
	while (store[count] && store[count + 1])
	{
		if (store[count + 1][0] == 's')
			store[count] = join(store[count], va_arg(ap, char *), (count == 0));
		else if (store[count + 1][0] == 'd')
		{
			tmp = ft_itoa(va_arg(ap, int));
			store[count] = join(store[count], tmp, 1);
			free(tmp);
		}
		count++;
	}
	tmp = ft_strdup(&store[count][1]);
	free(store[count]);
	store[count] = ft_strdup(tmp);
	free(tmp);
	return (join_tab(store));
}
