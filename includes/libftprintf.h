/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:38:43 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/02 14:01:25 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h> 
# include <wchar.h> 
typedef struct			s_arg
{
	int				index;
	int				preci;
	int				hpreci;
	int				field;
	int				islower;
	int				ishtg;
	int				isplus;
	int				ismins;
	int				ispace;
	int				isl;
	int				ish;
	int				isj;
	int				isz;
	int				is0;
	int				char0;
	char			arg;
	char			*format;
	char			*hformat;
	size_t			length;
	struct s_arg	*next;
}						t_arg;
unsigned long long int	get_max(int sign);
void					switch_minus(char *tmp, t_arg *new);
void					get_format(t_arg *new, va_list ap);
void					set_format(t_arg *new);
t_arg					*new_arg(char *str, va_list ap);
t_arg					*map_arg(char **store, va_list ap);
int						ft_printf(const char* format, ...);
int						ft_format(const char *format, va_list ap);

int						is_charg(char c);
int						is_flag(char c);
int						is_arg(t_arg *new);
int						is_str(t_arg *new);
int						is_num(t_arg *new);
int						is_deci(t_arg *new);
int						is_hexa(t_arg *new);
int						is_octal(t_arg *new);
int						is_string(t_arg *new);
int						is_char(t_arg *new);
int						is_unsign(t_arg *new);
#endif
