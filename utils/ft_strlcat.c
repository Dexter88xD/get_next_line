/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:13:19 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/10 12:17:01 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (!dst && size == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (size + len_src);
	dst = dst + len_dst;
	while (size-- > len_dst + 1 && *src != '\0')
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (len_dst + len_src);
}
