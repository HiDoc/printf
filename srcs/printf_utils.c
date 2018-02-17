/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:00:23 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/17 12:35:41 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	free_list(t_arg *list)
{
	t_arg	*iter;
	int		percent;

	iter = list;
	percent = 0;
	while (iter)
	{
		if (iter->arg == '%')
			percent++;
		list = iter;
		if (is_str(iter) && !iter->islower)
		{
			if (iter->wformat != NULL)
				free(iter->wformat);
		}
		if (iter->arg == '%')
		{
			if (percent % 2 == 0)
				free(iter->format);
			else if (iter->hformat)
				free(iter->hformat);
		}
		iter = iter->next;
		free(list);
	}
}
