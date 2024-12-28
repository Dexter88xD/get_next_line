/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:56:03 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/12 01:17:26 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	char			*sub_sub;
	unsigned int	i;

	if (s == NULL)
		return (0);
	i = ft_strlen(s);
	if (start >= i)
		return (ft_calloc(1, 1));
	if (len >= i - start)
		len = i - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub_sub = sub;
	s = s + start;
	while (len > 0 && *s)
	{
		*sub++ = *s++;
		len--;
	}
	*sub = '\0';
	return (sub_sub);
}
