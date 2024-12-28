/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:39:38 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/14 12:42:27 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	if (!s[i])
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	*ft_allocate(char const *s, int start, size_t len)
{
	char	*sub_sub;
	int		i;

	i = 0;
	sub_sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub_sub == NULL)
		return (NULL);
	while (len > 0 && s[start])
	{
		sub_sub[i++] = s[start++];
		len--;
	}
	sub_sub[i] = '\0';
	return (sub_sub);
}

static void	free_all(char **s, int j)
{
	while (j > 0)
		free(s[j--]);
	free(s);
}

static char	**ft_fill(char **result, char *s, char c, int word)
{
	int	i;
	int	j;
	int	start_pos;

	i = 0;
	j = 0;
	while (j < word)
	{
		while (s[i] == c && s[i])
			i++;
		start_pos = i;
		while (s[i] != c && s[i])
			i++;
		result[j] = ft_allocate(s, start_pos, i - start_pos);
		if (!result[j])
		{
			free_all(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**result;

	if (!s)
		return (0);
	word = count_words((char *)s, c);
	result = (char **)malloc((word + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_fill(result, (char *)s, c, word);
	return (result);
}
