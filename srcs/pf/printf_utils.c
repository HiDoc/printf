/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:00:23 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/01 13:41:53 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	nfree(void *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

void	switch_minus(char *tmp, t_arg *new)
{
	if (new->ismins)
		new->format = ft_strdjoin(new->format, tmp);
	else
		new->format = ft_strdjoin(tmp, new->format);
}

wchar_t	*str_to_wstr(const char *str)
{
	wchar_t	*new;
	size_t	size;
	size_t	count;

	if (str == NULL)
		return (NULL);
	size = ft_strlen(str);
	if ((new = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))) == NULL)
		return (NULL);
	count = 0;
	while (count < size)
	{
		new[count] = (int)str[count];
		count++;
	}
	new[size] = '\0';
	return (new);
}

int		free_error(t_arg *list)
{
	t_arg *to_free;

	if (list->format != NULL)
		nfree(list->format);
	if (list->next)
	{
		to_free = list->next;
		list->next = NULL;
		while (to_free)
		{
			list = to_free;
			if (to_free->format)
				nfree(to_free->format);
			if (to_free->hformat)
				nfree(to_free->hformat);
			to_free = to_free->next;
			nfree(list);
		}
	}
	return (-1);
}

void	free_list(t_arg *list)
{
	t_arg	*iter;

	iter = list;
	while (iter)
	{
		list = iter;
		if (list->format)
			nfree(list->format);
		if (is_str(iter) && !iter->islower)
		{
			if (iter->wformat != NULL)
				nfree(iter->wformat);
		}
		iter = iter->next;
		nfree(list);
	}
}
