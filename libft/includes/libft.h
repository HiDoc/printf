/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:39:39 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/21 17:06:43 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(x) (x < 0 ? -x : x)
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char			*ft_strset(char *str, char c, size_t size);
int				ft_abs(int c);
char			*ft_strljoin(char *s1, char *s2);
int				ft_strchri(char *str, char c);
char			*ft_strdupcat(const char *s1, const char *s2);
char			*ft_strndup(const char *s1, size_t n);
int				ft_isxdigit(int c);
unsigned int	ft_pow(int num, int pow);
void			ft_lowercase(char *s);
void			ft_capitalize(char *s);
int				ft_isspace(char c);
size_t			ft_strlcat(char *restrict dst, const char *restrict src,
				size_t size);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s);
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *restrict dst, const void *restrict src,
				size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memccpy(void *restrict dst, const void *restrict src,
				int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strncat(char *restrict s1, const char *restrict s2,
				size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_strclr(char *s);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstpush(t_list **alst, t_list *new);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int				ft_listsize(t_list **alst);
#endif
