/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:38:43 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 16:05:18 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_args
{
	char			*line;
	char			*format;
	char			*argument;
	char			attribut;
	int				precision;
	int				field;
	struct s_args	*next;
}				t_args;
t_args			*ft_new_arg(char *str);
char			*ft_join_arg(t_args *list);
void			ft_map_args(t_args *list, va_list ap);
int				ft_printf(const char* format, ...);
char			*ft_format(const char *format, va_list ap);
const char		*ft_switch(char c, va_list ap);
char			ft_isargument(char c);
int				ft_haveflag(char *str);
char			ft_isflag(char c);
void			set_precision(t_args *arg);
int				set_attribute(t_args *arg, va_list ap);
void			set_field(t_args *arg);
#endif
