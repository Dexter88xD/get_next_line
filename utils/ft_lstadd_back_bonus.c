/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:16:55 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/14 16:05:27 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if ((*lst) == NULL)
		ft_lstadd_front(lst, new);
	else
	{
		current = ft_lstlast((*lst));
		(*current).next = new;
	}
}
