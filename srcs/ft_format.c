/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/22 17:41:03 by fmadura          ###   ########.fr       */
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

static char	*ft_precision(char *str, int index, char *format)
{
	int		precision;
	int		len;
	char	*tmp;
	char	flag;

	len = (int)ft_strlen(format);
	flag = str[index];
	if ((precision = ft_strnchri(str, '.', index)) > -1)
	{
		precision = ft_atoi(&str[precision + 1]);
		if (precision < len && precision > 0 && (flag != 'x'))
		{
			tmp = ft_strsub(format, 0, precision);
			format = ft_strdup(tmp);
			free(tmp);
		}
		else if (precision == 0 && index != (int)ft_strlen(str) && !(flag == 'd' || flag == 'D'))
		{

			free(format);
			format = ft_strdup(" ");
		}
		else if (precision > len && len != 0 )
		{
			tmp = ft_strnew(precision - len);
			ft_strset(tmp, flag == 's' ? ' ' : '0', precision - len);
			format = ft_strdjoin(tmp, format);
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
	while (count < index && (!ft_isdigit(str[count]) || str[count] == '0') && str[count] != '.')
		count++;
	if (count < index && str[count] != '.')
	{
		field = ft_atoi(&str[count]);
		if (field && ft_strcmp(format, "(null)") != 0 && field > (len = ft_strlen(format)))
		{
			len = field - len;
			tmp = ft_strnew(len);
			ft_strset(tmp, get_space(str, index), len);
			if (ft_strchri(str, '-') != -1 && ft_strchri(str, '-') < index)
				format = ft_strdjoin(format, tmp);
			else
				format = ft_strdjoin(tmp, format);
		}
	}
	return (format);
}

static char *extra_flags(char *str, int index, char *format)
{
	char	flag;
	int		num;

	flag = str[index];
	num = ft_atoi(format);
	if (ft_strnchri(str, '+', index) > -1 && format[0] != '-' && flag != 'u')
		format = ft_strrjoin("+", format);
	else if (ft_strnchri(str, '#', index) > -1 && (flag == 'x' || flag == 'X') && num != 0)
		format = ft_strrjoin(ft_islower(flag) ? "0x" : "0X", format);
	else if ((ft_strnchri(str, '#', index) > -1) && (flag  == 'o' || flag == 'O') && num != 0)
		format = ft_strrjoin("0", format);
	else if (format[1] && format[1] == ' ')
		format = ft_strrjoin(" ", format);
	return (format);
}

static void	map_tab(char **tab, va_list ap)
{
	int		count;
	int		index;
	char	*str;
	char	*cut;
	char	*new;
	char	*format;

	count = 0;
	while (tab[count])
	{
		str = tab[count];
		index = 0;
		if (ft_strchri(str, '%') != -1)
		{
			while (str[index] && !(ft_isargument(str[index])))
				index++;
			cut = ft_strsub(str, index + 1, (int)ft_strlen(str));
			if (index != (int)ft_strlen(str))
				format = (char *)ft_switch(str, index, ap);
			else 
				(format = ft_chartostr('%'));
			format = ft_precision(str, index, format);
			format = extra_flags(str, index, format);
			format = ft_field(str, index, format);
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
