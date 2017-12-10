/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:45:09 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/21 20:45:28 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (lst != NULL && f != NULL)
	{
		new = f(lst);
		lst = lst->next;
		start = new;
		while (lst != NULL)
		{
			new->next = f(lst);
			new = new->next;
			lst = lst->next;
		}
		return (start);
	}
	return (NULL);
}
