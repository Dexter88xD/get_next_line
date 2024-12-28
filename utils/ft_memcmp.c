/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:45:01 by sohamdan          #+#    #+#             */
/*   Updated: 2024/10/26 09:59:21 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr1 < *ptr2)
			return (*ptr1 - *ptr2);
		else if (*ptr1 > *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}
