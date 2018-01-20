/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/20 16:34:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	get_space(char *str, int len)
{
	int count = 0;
	char c = ' ';
	if (ft_strnchri(str, '-', len) > -1)
		return (' ');
	while (str[count] && count < len)
	{
		if (ft_isdigit(str[count]))
			return (str[count] == '0' ? '0' : c);
		count++;
	}
	return (c);
}

static void	map_tab(char **tab, va_list ap)
{
	int		count;
	int		count2;
	char	*str;
	char	*cut;
	char	*new;
	char	*format;
	int 	field;
	int		precision;

	count = 0;
	while (tab[count])
	{
		str = tab[count];
		count2 = 0;
		field = 0;
		precision = 0;
		if (ft_strchri(str, '%') != -1)
		{
			while (str[count2] && !(ft_isargument(str[count2])))
				count2++;
			field = ft_atoi(&str[1]);
			cut = ft_strsub(str, count2 + 1, (int)ft_strlen(str));
			format = (char *)ft_switch(str[count2], ft_strnchri(str, 'l', count2) > 0 ? 'l' : '0', ap);
			if ((precision = ft_strnchri(str, '.', count2)) > -1 && str[count2] != 'd')
			{
				precision = ft_atoi(&str[precision + 1]);
				if (precision < (int)ft_strlen(format) && precision >= 0)
				{
					char *tmp2 = ft_strsub(format, 0, precision);
					format = ft_strdup(tmp2);
					free(tmp2);
				}	
			}
			if (ft_strnchri(str, '+', count2) > -1 && format[0] != '-')
				format = ft_strrjoin("+", format);
			else if (ft_strnchri(str, '#', count2) > -1 && (str[count2] == 'x' || str[count2] == 'X'))
				format = ft_strrjoin(ft_islower(str[count2]) ? "0x" : "0X", format);
			if (field && ft_strcmp(format, "(null)") != 0 && ft_abs(field) > (int)ft_strlen(format))
			{
				int len = ft_abs(field) - ft_strlen(format);
				char *tmp = ft_strnew(len);
				ft_strset(tmp, get_space(str, count2), len);
				if (field < 0)
					format = ft_strdjoin(format, tmp);
				else
					format = ft_strdjoin(tmp, format);
			}
						new = ft_strdjoin(format, cut);
			free(tab[count]);
			tab[count] = new;
		}
		count++;
	}
}

static char	*ft_tabjoin(char **store)
{
	char	*str;
	int		count;

	count = 1;
	str = ft_strdup(store[0]);
	free(store[0]);
	while (store[count])
	{
		str = ft_strdjoin(str, store[count]);
		count++;
	}
	free(store);
	return (str);
}

char		*ft_format(const char *format, va_list ap)
{
	char	**store;

	if (ft_strchri((char *)format, '%') == -1)
		return (ft_strdup((char *)format));
	store = ft_strcut(format, '%');
	map_tab(store, ap);
	return (ft_tabjoin(store));
}
