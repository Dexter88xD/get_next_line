/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:19:53 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/12 01:45:05 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compizz(const char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		len;
	int		end;
	int		start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s1) - 1;
	while (compizz(s1[start], set) == 1 && s1[start])
		start++;
	while (compizz(s1[end], set) == 1 && s1[start])
		end--;
	len = end - start + 1;
	trim = (char *)malloc((len + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	len = 0;
	while (start < end + 1)
		trim[len++] = s1[start++];
	trim[len] = '\0';
	return (trim);
}
