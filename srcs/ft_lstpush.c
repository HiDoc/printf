/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:38:42 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/29 16:43:19 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		while ((*alst)->next != NULL)
			alst = &(*alst)->next;
		(*alst)->next = new;
	}
}
