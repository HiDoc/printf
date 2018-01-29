/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:38:43 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/29 11:19:03 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h> 
typedef struct		s_arg
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
	size_t			length;
	struct s_arg	*next;
}					t_arg;
void				set_arg(t_arg *new, char *str);
void				get_format(t_arg *new, va_list ap);
void				set_format(t_arg *new);
t_arg				*new_arg(char *str, va_list ap);
t_arg				*map_arg(char **store, va_list ap);
int					ft_printf(const char* format, ...);
int					ft_format(const char *format, va_list ap);
int					is_arg(char c);
int					is_str(char c);
int					is_num(char c);
#endif
