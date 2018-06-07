/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:34:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/07 20:43:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		if_arg(t_arg *new, char c, int count)
{
	if (!(new->field) && !(new->preci) && ft_isdigit(c) && c != '0')
		new->field = count;
	new->ispace += (c == ' ');
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
	if (!(new->hpreci) && c == '*')
		new->wildfield = count;
	if (new->hpreci && c == '*')
		new->wildpreci++;
}

static t_arg	*get_field_preci(t_arg *new, char *str)
{
	if (new->field > 0 && new->field < new->wildfield)
		new->field = 0;
	new->field = new->field ? ft_atoi(&str[new->field]) : 0;
	new->preci = new->preci ? ft_atoi(&str[new->preci]) : 0;
	return (new);
}

static int		iso_arg(char c)
{
	return (is_charg(c) || c == 'j' || c == 'l' ||
			c == 'z' || c == 'h' || c == '.');
}

static t_arg	*set_charg(t_arg *new, char *str, int count)
{
	if (is_charg(str[count]))
	{
		new->arg = str[count];
		new->index = count;
		new->islower = ft_islower(new->arg);
	}
	else
	{
		new->arg = '%';
		new->format = ft_strdup2("%");
	}
	return (new);
}

t_arg			*set_arg(t_arg *new, char *str)
{
	int		count;

	count = 0;
	while (str[count] && !(is_charg(str[count])))
	{
		if (!is_flag(str[count]) && !(is_flag_bonus(str[count])))
			break ;
		if (!new->field && !new->is0 && str[count] == '0' &&
			!new->hpreci && !iso_arg(str[count + 1]))
		{
			new->is0 = 1;
			while (str[count] == '0')
				count++;
		}
		else
		{
			if_arg(new, str[count], count);
			count++;
		}
	}
	new = set_charg(new, str, count);
	new = get_field_preci(new, str);
	return (new);
}
