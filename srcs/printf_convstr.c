/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:51:18 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/11 12:18:22 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	format_bigstr(t_arg *new)
{
	char	*tmp;
	size_t	len;

	len = sizewstr(new->wformat);
	tmp = NULL;
	if (len && new->field && (int)new->field - (int)len > 0)
	{
		tmp = ft_strnew(new->field - len);
		ft_strset(tmp, ' ', new->field - len);
		new->hformat = tmp;
	}
}

void		format_str(t_arg *new)
{
	char	*tmp;
	int		len;

	if (!new->islower)
	{
		format_bigstr(new);
		return ;
	}
	len = ((new->format != NULL) ? ft_strlen(new->format) : 0);
	if (new->hpreci && new->preci < len && new->format[0])
	{
		tmp = ft_strsub(new->format, 0, new->preci);
		free(new->format);
		new->format = ft_strdup(tmp);
		free(tmp);
		len = (int)ft_strlen(new->format);
	}
	if (new->field - len > 0)
	{
		tmp = ft_strnew(new->field - len);
		ft_strset(tmp, ' ', new->field - len);
		switch_minus(tmp, new);
	}
}
