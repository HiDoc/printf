/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:38:43 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 11:02:50 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_args
{
	char			*line;
	char			*flags;
	char			attribut;
	int				precision;
	int				length;
	struct s_args	*next;
}				t_args;
t_args			*ft_new_arg(char *str);
int				ft_printf(const char* format, ...);
char			*ft_format(const char *format, va_list ap);
const char		*ft_switch(char *line, char c, va_list ap);
char			ft_isargument(char c);
int				ft_haveflag(char *str);
char			ft_isflag(char c);
int				ft_isfield(char *str);
int				ft_isprecision(char *str);
#endif
