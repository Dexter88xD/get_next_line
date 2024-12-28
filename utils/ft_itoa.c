/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:40:45 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/10 10:08:22 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative(char *s, long nn)
{
	if (nn < 0)
	{
		s[0] = '-';
		nn *= -1;
	}
	return (nn);
}

static long	len_iint(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		len_len;

	len = len_iint(n);
	len_len = len;
	s = (char *)malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (n == -2147483648)
		return ((char *)ft_memcpy(s, "-2147483648", 12));
	n = ft_negative(s, n);
	if (n >= 0 && n <= 9)
	{
		s[len - 1] = n + 48;
		n /= 10;
	}
	while (n > 0)
	{
		s[len-- - 1] = (n % 10) + 48;
		n /= 10;
	}
	s[len_len] = '\0';
	return (s);
}
