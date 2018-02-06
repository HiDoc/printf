/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:04:22 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/06 14:07:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcslen (const wchar_t *s)
{
	size_t len = 0;

	while (s[len] != L'\0')
	{
		if (s[++len] == L'\0')
			return (len);
		if (s[++len] == L'\0')
			return (len);
		if (s[++len] == L'\0')
			return (len);
		++len;
	}
	return (len);
}
