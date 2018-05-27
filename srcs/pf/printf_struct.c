/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:50:32 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/07 16:18:53 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		zero_arg_plus(t_arg *new)
{
	new->isl = 0;
	new->ish = 0;
	new->isj = 0;
	new->isz = 0;
	new->is0 = 0;
	new->arg = 0;
	new->char0 = 0;
	new->wildpreci = 0;
	new->wildfield = 0;
}

static t_arg	*zero_arg(void)
{
	t_arg *new;

	if ((new = (t_arg *)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	new->index = 0;
	new->preci = 0;
	new->hpreci = 0;
	new->field = 0;
	new->islower = 0;
	new->ishtg = 0;
	new->isplus = 0;
	new->ismins = 0;
	new->ispace = 0;
	new->hformat = NULL;
	new->wformat = NULL;
	new->format = NULL;
	new->next = NULL;
	zero_arg_plus(new);
	return (new);
}

t_arg			*new_arg(char *str, va_list ap)
{
	t_arg	*new;
	char	*tmp;

	if ((new = zero_arg()) == NULL)
		return (NULL);
	new->error = 0;
	if (str[0] == '%')
	{
		set_arg(new, str);
		set_format(new, ap);
		if (new->arg != '%')
			if (new->index < (int)ft_strlen(str) && str[new->index + 1])
			{
				tmp = ft_strsub(str, new->index + 1, ft_strlen(str));
				new->format = (new->format) ? ft_strljoin(new->format, tmp)
					: ft_strdup(tmp);
				free(tmp);
			}
	}
	else
		new->format = ft_strdup(str);
	if (new->is0 && new->ismins)
		new->is0 = 0;
	return (new);
}

t_arg			*map_arg(char **store, va_list ap)
{
	int		count;
	t_arg	*iter;
	t_arg	*first;

	count = 1;
	if ((first = new_arg(store[0], ap)) == NULL)
		return (NULL);
	free(store[0]);
	iter = first;
	while (store[count])
	{
		if (iter->error == 1)
			return (first);
		iter->next = new_arg(store[count], ap);
		iter = iter->next;
		free(store[count]);
		count++;
	}
	free(store);
	return (first);
}
