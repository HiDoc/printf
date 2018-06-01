/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:34:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/01 13:42:00 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		if_arg_specialcases(t_arg *new, char c, int count)
{
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
	if (!(new->hpreci) && c == '*')
		new->wildfield = count;
	if (new->hpreci && c == '*')
		new->wildpreci++;
}

static void		if_arg(t_arg *new, char c, int count)
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
	if_arg_specialcases(new, c, count);
}

static t_arg	*get_field_preci(t_arg *new, char *str)
{
	if (new->field > 0 && new->field < new->wildfield)
		new->field = 0;
	new->field = new->field ? ft_atoi(&str[new->field]) : 0;
	new->preci = new->preci ? ft_atoi(&str[new->preci]) : 0;
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
		if (new->format)
			free(new->format);
		new->format = ft_strdup2("%");
	}
	new = get_field_preci(new, str);
	return (new);
}
