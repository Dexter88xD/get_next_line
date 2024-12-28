/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:57:01 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/12 01:07:24 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr_big;
	size_t	l;
	size_t	i;

	ptr_big = (char *)big;
	if (*little == 0)
		return (ptr_big);
	if (len == 0)
		return (0);
	l = ft_strlen(little);
	i = 0;
	while (i <= len - l && *ptr_big)
	{
		if (ft_strncmp(ptr_big, little, l) == 0 && l <= len)
			return (ptr_big);
		ptr_big++;
		i++;
	}
	return (0);
}
