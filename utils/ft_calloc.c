/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:23:50 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/09 23:34:47 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*holder;

	holder = (void *)malloc(nmemb * size);
	if (holder == NULL)
		return (NULL);
	ft_bzero(holder, nmemb * size);
	return (holder);
}
