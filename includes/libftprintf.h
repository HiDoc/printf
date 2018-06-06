/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:38:43 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/05 11:51:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define SPEED 750
# include "libft.h"
# include <stdarg.h>

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
	int				wildpreci;
	int				wildfield;
	char			arg;
	char			*format;
	char			*hformat;
	wchar_t			*wformat;
	int				error;
	struct s_arg	*next;
}						t_arg;

unsigned long long int	get_max(int sign);

void					switch_char(t_arg *arg, va_list ap);
void					switch_minus(char *tmp, t_arg *arg);
void					switch_num(t_arg *arg, va_list ap);

t_arg					*new_arg(char *str, va_list ap);
t_arg					*map_arg(char **store, va_list ap);

t_arg					*set_arg(t_arg *arg, char *str);
t_arg					*set_format(t_arg *arg, va_list ap);
void					set_wildcards(t_arg *arg, va_list ap);

int						ft_printf(const char *format, ...);
int						ft_format(const char *format, va_list ap);

int						is_arg(t_arg *arg);
int						is_char(t_arg *arg);
int						is_charg(char c);
int						is_deci(t_arg *arg);
int						is_flag(char c);
int						is_flag_bonus(char c);
int						is_hexa(t_arg *arg);
int						is_num(t_arg *arg);
int						is_octal(t_arg *arg);
int						is_str(t_arg *arg);
int						is_string(t_arg *arg);
int						is_unsign(t_arg *arg);

int						print_args(t_arg *arg, size_t len, int pc, int error);
int						print_bigstr(t_arg *arg);
int						print_wchar(t_arg *arg);
int						print_buffer(char *str, int freestr);

int						sizewchar(wchar_t t);
int						sizewstr(wchar_t *str);
int						checkwchar(wchar_t t);
int						checkwstr(t_arg *arg);
int						switch_wchar(int c, int iswchar);

void					format_char(t_arg *arg);
void					format_str(t_arg *arg);
void					format_htg(t_arg *arg);
void					format_ptr(t_arg *arg);
void					format_float(t_arg *arg, va_list ap);
void					format_sci(t_arg *arg, va_list ap);
void					format_num(t_arg *arg, va_list ap);
void					format_deci(t_arg *arg, va_list ap);
void					format_gen(t_arg *arg, va_list ap);

char					*befor_dot(double num);
char					*after_dot(double num, size_t preci);

wchar_t					*str_to_wstr(const char *str);
void					free_list(t_arg *list);
void					nfree(void *to_free);
int						free_error(t_arg *list);
#endif
