/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:31:46 by sohamdan          #+#    #+#             */
/*   Updated: 2024/10/26 11:57:56 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buffer;
	int		len;

	len = ft_strlen(s);
	buffer = (char *)malloc((len + 1) * sizeof(*s));
	if (buffer == NULL)
		return (NULL);
	buffer = ft_memcpy(buffer, s, len);
	*(buffer + len) = '\0';
	return (buffer);
}
