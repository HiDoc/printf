/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:14:40 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 18:40:31 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (s == NULL || (end = ft_strlen(s) - 1) == 0)
		return (NULL);
	while (ft_space(s[start]))
		start++;
	while (ft_space(s[end]) && end > 0)
		end--;
	if (start > end)
		return (ft_strnew(ft_strlen(s)));
	else if (start == 0 && end == 0)
		return (ft_strdup(s));
	else
		return (ft_strsub(s, start, (end - start + 1)));
}
