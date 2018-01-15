/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:24:04 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/20 19:26:46 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list **alst)
{
	size_t	count;

	count = 0;
	if (alst != NULL)
		while (alst[count]->next != NULL)
			count++;
	return (count);
}
