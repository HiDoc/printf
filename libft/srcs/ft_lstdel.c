/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:43:24 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 19:54:25 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst != NULL && del != NULL)
	{
		while (*alst != NULL)
		{
			tmp = *alst;
			*alst = (**alst).next;
			ft_lstdelone(&tmp, del);
		}
	}
}
