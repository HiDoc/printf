/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:50:32 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/31 11:59:38 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	if_arg(t_arg *new, char c, int count)
{
	if (!(new->field) && !(new->preci) && ft_isdigit(c) && c != '0')
		new->field = count;
	if (c == ' ')
		new->ispace++;
	if (c == '-')
		new->ismins++;
	if (c == '+')
		new->isplus++;
	if (c == '#')
		new->ishtg++;
	if (c == '.')
		new->hpreci++;
	if (!(new->preci) && c == '.')
		new->preci = count + 1;
	if (c == 'l')
		new->isl++;
	if (c == 'h')
		new->ish++;
	if (c == 'j')
		new->isj++;
	if (c == 'z')
		new->isz++;
	if (!(new->preci) && !(new->field) && c == '0')
		new->is0++;
}

static void	set_arg(t_arg *new, char *str)
{
	int		count;

	count = 0;
	while (str[count] && !(is_charg(str[count])))
	{
		if (!is_flag(str[count]))
			break;
		if_arg(new, str[count], count);
		count++;
	}
	if (is_charg(str[count]))
	{
		new->arg = str[count];
		new->index = count;
		new->islower = ft_islower(new->arg);
	}
	else
	{
		new->arg = '%';
		new->format = ft_strdup("%");
		new->hformat = ft_strdup2(&str[1]);
	}
	if (new->field)
		new->field = ft_atoi(&str[new->field]);
	if (new->preci)
		new->preci = ft_atoi(&str[new->preci]);
	if (count > 2)
		new->ispace = 0;
}

static void	zero_arg(t_arg *new)
{
	new->index = 0;
	new->preci = 0;
	new->hpreci = 0;
	new->field = 0;
	new->islower = 0;
	new->ishtg = 0;
	new->isplus = 0;
	new->ismins = 0;
	new->ispace = 0;
	new->isl = 0;
	new->ish = 0;
	new->isj = 0;
	new->isz = 0;
	new->is0 = 0;
	new->arg = 0;
	new->char0 = 0;
	new->hformat = NULL;
	new->next = NULL;
	new->length = 0;
}

t_arg		*new_arg(char *str, va_list ap)
{
	t_arg	*new;
	char	*tmp;

	if ((new = (t_arg *)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	zero_arg(new);
	if (str[0] == '%')
	{
		set_arg(new, str);
		if (new->arg != '%')
		{
			get_format(new, ap);
			set_format(new);
			if (new->index < (int)ft_strlen(str) && str[new->index + 1])
			{
				tmp = ft_strsub(str, new->index + 1, ft_strlen(str));
				if (new->format)
					new->format = ft_strljoin(new->format, tmp);
				else
					new->format = ft_strdup(tmp);
				free(tmp);
			}
		}
		else
			set_format(new);
	}
	else
	{
		new->format = ft_strdup(str);
		new->length = ft_strlen(str);
	}
	return (new);
}

t_arg		*map_arg(char **store, va_list ap)
{
	int		count;
	t_arg	*iter;
	t_arg	*first;

	count = 1;
	first = new_arg(store[0], ap);
	free(store[0]);
	iter = first;
	while (store[count])
	{
		iter->next = new_arg(store[count], ap);
		iter = iter->next;
		free(store[count]);
		count++;
	}
	free(store);
	return (first);
}
