/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/21 17:22:33 by fmadura          ###   ########.fr       */
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
/**
  static int	isnum_flag(char c)
  {
  return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
  || c == 'D' || c == 'I' || c == 'O' || c == 'U' || c == 'X');
  }
 **/
static char	*ft_precision(char *str, char index, char *format)
{
	int		precision;
	int		len;
	char	*tmp;

	len = (int)ft_strlen(format);
	if ((precision = ft_strnchri(str, '.', index)) > -1)
	{
		precision = ft_atoi(&str[precision + 1]);
		if (precision < len && precision > 0 && (str[(unsigned)index] != 'x'))
		{
			tmp = ft_strsub(format, 0, precision);
			format = ft_strdup(tmp);
			free(tmp);
		}
		else if (precision == 0)
		{
			free(format);
			format = ft_strdup(" ");
		}
	}
	return (format);
}

static char	*ft_field(char *str, int index, char *format)
{
	int 	field;
	int 	count;
	int 	len;
	char	*tmp;

	count = 0;
	while (count < index && !ft_isdigit(str[count]) && str[count] != '.')
		count++;
	if (count < index && str[count] != '.')
	{
		field = ft_atoi(&str[count]);
		if (field && ft_strcmp(format, "(null)") != 0 && field > (len = ft_strlen(format)))
		{
			len = field - len;
			tmp = ft_strnew(len);
			ft_strset(tmp, get_space(str, index), len);
			if (ft_strchri(str, '-') != -1 && ft_strchri(str, '-') < index )
				format = ft_strdjoin(format, tmp);
			else
				format = ft_strdjoin(tmp, format);
		}
	}
	return (format);
}
static void	map_tab(char **tab, va_list ap)
{
	int		count;
	int		count2;
	char	*str;
	char	*cut;
	char	*new;
	char	*format;

	count = 0;
	while (tab[count])
	{
		str = tab[count];
		count2 = 0;
		if (ft_strchri(str, '%') != -1)
		{
			while (str[count2] && !(ft_isargument(str[count2])))
				count2++;
			cut = ft_strsub(str, count2 + 1, (int)ft_strlen(str));
			if (count2 != (int)ft_strlen(str))
				format = (char *)ft_switch(str[count2], ft_strnchri(str, 'l', count2) > 0 ? 'l' : '0', ap);
			else 
				(format = ft_chartostr('%'));
			format = ft_precision(str, count2, format);
			if (ft_strnchri(str, '+', count2) > -1 && format[0] != '-')
				format = ft_strrjoin("+", format);
			else if (ft_strnchri(str, '#', count2) > -1 && (str[count2] == 'x' || str[count2] == 'X') && ft_atoi(format) != 0)
				format = ft_strrjoin(ft_islower(str[count2]) ? "0x" : "0X", format);
			else if ((ft_strnchri(str, '#', count2) > -1 || ft_strnchri(str, '-', count2) > -1)
					&& (str[count2] == 'o' || str[count2] == 'O') && ft_atoi(format) != 0)
				format = ft_strrjoin("0", format);
			format = ft_field(str, count2, format);
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
	if (store[1] && ft_strchri(store[0], '%') > -1 && ft_strchri(store[1], '%') > -1)
	{
		count++;
		free(store[1]);
	}
	free(store[0]);
	while (store[count])
	{
		if (!(store[count + 1] && ft_strchri(store[count], '%') > -1 && ft_strchri(store[count + 1], '%') > -1))
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
