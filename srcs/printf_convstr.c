/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:51:18 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/13 17:37:17 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	format_bigstr(t_arg *new)
{
	char	*tmp;
	size_t	len;
	size_t	count;

	count = 0;
	len = sizewstr(new->wformat);
	tmp = NULL;
	if (new->hpreci)
	{
		if (!new->preci)
			count = len;
		else if (new->field > new->preci)
		{
			if (len && sizewchar(new->wformat[0]) > new->preci)
				count = len;
			else if (len > (size_t)new->preci)
				count = new->field - new->preci - 1;
		}
	}
	if (len && new->field && (int)(new->field + count) > (int)len)
	{
		tmp = ft_strnew(new->field + count - len);
		ft_strset(tmp, ' ', new->field + count - len);
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
