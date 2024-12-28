/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:56:54 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/14 03:22:56 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*previous;

	if (!lst)
		return (NULL);
	current = lst;
	previous = current;
	while (current != NULL)
	{
		current = (*current).next;
		if (current != NULL)
			previous = current;
	}
	return (previous);
}
