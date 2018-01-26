/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:06:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/26 17:48:24 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
typedef struct	s_arg
{
	int		index;
	int		preci;
	int		hpreci;
	int		field;
	int		islower;
	int		ishtg;
	int		isplus;
	int		ismins;
	int		ispace;
	int		isl;
	int		ish;
	int		isj;
	int		isz;
	int		is0;
	int		char0;
	char	arg;
	char	*format;
	struct s_arg *next;
}				t_arg;

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

static void		set_arg(t_arg *new, char *str)
{
	int count;

	count = 0;
	while (!(ft_isargument(str[count])))
	{
		if_arg(new, str[count], count);
		count++;
	}
	if (count < (int)ft_strlen(str))
	{
		new->arg = str[count];
		new->index = count;
		new->islower = ft_islower(new->arg);
	}
	else
	{
		new->arg = '%';
		new->format = ft_strdup("%");
	}
	if (new->field)
		new->field = ft_atoi(&str[new->field]);
	if (new->preci)
		new->preci = ft_atoi(&str[new->preci]);
}

static int	ft_isletter(char flag)
{
	return (ft_strchri("sScC", flag) > -1);
}

static void get_arg(t_arg *new, va_list ap)
{
	long long	num;
	int 		base;

	num = 0;
	base = 10;
	if (ft_isnumber(new->arg))
	{
		if (ft_strchri("dDiI", new->arg) > -1 && !(new->isz))
		{
			if (new->isl == 2 || new->isj)
				num = va_arg(ap, long long);
			else if (new->isl == 1 || !(new->islower))
				num = va_arg(ap, long);
			else
				num = va_arg(ap, int);
		}
		else
		{
			if (new->isl == 2 || new->isj)
				num = va_arg(ap, unsigned long long);
			else if (new->arg == 'U' || new->isl == 1)
				num = va_arg(ap, unsigned long);
			else
				num = va_arg(ap, unsigned int);
		}
		if (ft_strchri("oOxX", new->arg) > -1)
			base = ((new->arg) == 'o' || (new->arg) == 'O' ? 8 : 16);
		if (new->ish == 1)
			num = (short)num;
		if (new->ish == 2)
			num = (signed char)num;
		new->format = ft_ltoabase(num, base,
				new->islower ? "0123456789abcdef" : "0123456789ABCDEF");
	}
	else if (ft_isletter(new->arg))
	{
		if (new->arg == 'c' || new->arg == 'C')
			new->format = ft_chartostr((char)va_arg(ap, int));
		else
		{
			new->format = ft_strdup2(va_arg(ap, char *));
			if (new->format == NULL)
				new->format = ft_strdup("(null)");
		}
	}
}
static void		set_format(t_arg *new)
{
	int		len;
	int		diff;
	char	*tmp;

	len = (int)ft_strlen(new->format);
	if (ft_strchri("diouxDIOUX", new->arg) > -1)
	{
		if (new->format[0] == '0' && !(new->preci) && new->hpreci)
		{
			free(new->format);
			new->format = ft_strdup("");
		}
		else if (ft_strchri("xX", new->arg) > -1 && new->ishtg && new->format[0] != '0')
			new->format = ft_strrjoin((new->arg == 'x' ? "0x" : "0X"), new->format);
		if (ft_strchri("oO", new->arg) > -1 && (new->ishtg) && new->format[0] != '0')
			new->format = ft_strrjoin(("0"), new->format);
		if (ft_strchri("diDI", new->arg) > -1 && (new->isplus) && new->format[0] != '-')
			new->format = ft_strrjoin("+", new->format);
		if (new->preci > 0 && new->preci > len && ft_strchri("dDiIoOuU", new->arg) > -1)
		{
			tmp = ft_strnew(new->preci - len + (new->format[0] == '-'));
			ft_strset(tmp, '0', new->preci - len);
			if (new->format[0] == '-' || new->format[0] == '+')
			{
				tmp[0] = new->format[0];
				new->format[0] = '0';
			}
			new->format = ft_strdjoin(tmp, new->format);
		}
	}
	len = (int)ft_strlen(new->format);
	diff = new->field - len;
	if (ft_strchri("diouxDIOUX", new->arg) > -1)
	{
		if (new->ismins && diff > 0)
		{
			tmp = ft_strnew(diff);
			ft_strset(tmp, ' ', diff);
			new->format = ft_strdjoin(new->format, tmp);
		}
		else if (!(new->ismins) && new->is0 && diff > 0)
		{
			tmp = ft_strnew(diff);
			ft_strset(tmp, (new->preci > 0 ? ' ' : '0'), diff);
			if (ft_strchri("xX", new->arg) > -1 && new->ishtg)
			{
				new->format[1] = '0';
				tmp[1] = new->arg == 'x' ? 'x' : 'X';
			}
			else if (new->format[0] == '-' || new->format[0] == '+')
			{
				tmp[0] = new->format[0];
				new->format[0] = '0';
			}
			new->format = ft_strdjoin(tmp, new->format);
		}
		else if (diff > 0)
		{	
			tmp = ft_strnew(diff);
			ft_strset(tmp, ' ', diff);
			new->format = ft_strdjoin(tmp, new->format);
		}
	}
	else
	{
		if (new->preci > 0 && new->preci < len && new->format[0])
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
			if (new->ismins)
				new->format = ft_strdjoin(new->format, tmp);
			else
				new->format = ft_strdjoin(tmp, new->format);
		}
	}
}

static t_arg	*new_arg(char *str, va_list ap)
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
	new->isl = 0;
	new->ish = 0;
	new->isj = 0;
	new->isz = 0;
	new->is0 = 0;
	new->arg = 0;
	new->char0 = 0;
	new->next = NULL;
	if (str[0] == '%')
	{
		set_arg(new, str);
		if (new->arg != '%')
		{
			get_arg(new, ap);
			set_format(new);
			new->format = ft_strdjoin(new->format, ft_strsub(str, new->index + 1, ft_strlen(str)));
		}
		else 
			set_format(new);
	}
	else
		new->format = ft_strdup(str);
	return (new);
}

static t_arg	*map_arg(char **store, va_list ap)
{
	int count;
	count = 1;
	t_arg *first = new_arg(store[0], ap);
	free(store[0]);
	t_arg *iter;
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
}/*
	static void print_arg(t_arg *first)
	{
	t_arg *new;

	new = first;
	while (new != NULL)
	{
	printf("index : %d\n",new->index);
	printf("preci : %d\n",new->preci);
	printf("field : %d\n",new->field);
	printf("islower :%d\n",new->islower);
	printf("ishtg : %d\n",new->ishtg);
	printf("isplus : %d\n",new->isplus);
	printf("ismns :%d\n",new->ismins);
	printf("ispace :%d\n",new->ispace);
	printf("isl :%d\n",new->isl);
	printf("ish :%d\n",new->ish);
	printf("isj : %d\n",new->isj);
	printf("isz :%d\n",new->isz);
	printf("is0 :%d\n",new->is0);
	printf("arg :%c\n",new->arg);
	printf("char0 :%d\n",new->char0);
	printf("%s\n",new->format);
	new = new->next;
	}
	} */

static char	*join_args(t_arg *first)
{
	char	*tmp;
	int		countpc;

	countpc = 0;
	tmp = ft_strdup(first->format);
	if (first->arg == '%')
		countpc++;
	free(first->format);
	first = first->next;
	while (first)
	{
		if (countpc % 2 == 1 && first->arg == '%')
		{
			countpc++;
			free(first->format);
		}
		else
			tmp = ft_strdjoin(tmp, first->format);
		first = first->next;
	}
	return (tmp);
}

char		*ft_format(const char *format, va_list ap)
{
	char	**store;
	t_arg	*first;

	if (ft_strchri((char *)format, '%') == -1)
		return (ft_strdup((char *)format));	
	store = ft_strcut(format, '%');
	first = map_arg(store, ap);
	return (join_args(first));
}
