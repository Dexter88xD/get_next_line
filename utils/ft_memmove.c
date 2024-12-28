/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:06:06 by sohamdan          #+#    #+#             */
/*   Updated: 2024/10/23 23:46:29 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	const char	*ptr_src;

	if (n == 0)
		return (dest);
	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	while (ptr_dest > ptr_src && n > 0)
	{
		ptr_dest[n - 1] = ptr_src[n - 1];
		n--;
	}
	while (ptr_dest < ptr_src && n > 0)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
		n--;
	}
	return (dest);
}
