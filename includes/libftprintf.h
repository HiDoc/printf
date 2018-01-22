/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:38:43 by fmadura           #+#    #+#             */
/*   Updated: 2018/01/22 14:23:46 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
int				ft_printf(const char* format, ...);
char			*ft_format(const char *format, va_list ap);
const char		*ft_switch(char *str, int index, va_list ap);
char			ft_isargument(char c);
int				ft_haveflag(char *str);
char			ft_isflag(char c);
#endif
