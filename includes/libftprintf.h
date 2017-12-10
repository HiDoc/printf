/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:38:43 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/07 13:02:23 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char* format, ...);
char	*ft_format(const char *format, va_list ap);
char	ft_isargument(char c);
char	ft_isflag(char c);
int		ft_isfield(char *str);
int		ft_isprecision(char *str);
#endif
