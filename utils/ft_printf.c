/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:50:08 by sohamdan          #+#    #+#             */
/*   Updated: 2024/12/27 21:16:47 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long n, char c, int f)
{
	char	*hex_s;
	int		num;

	num = 0;
	hex_s = "0123456789abcdef";
	if (c == 'X')
		hex_s = "0123456789ABCDEF";
	else if (c == 'p' && f == 0)
		return (num += write(1, "(nil)", 5));
	else if (c == 'p' && f == 1)
		num += write(1, "0x", 2);
	if (n < 16)
		num += write(1, &hex_s[n], 1);
	else
	{
		num += ft_puthex(n / 16, c, 2);
		num += ft_puthex(n % 16, c, 2);
	}
	return (num);
}

int	ft_putnbr(long n)
{
	char	n_out;
	int		num;

	num = 0;
	if (n < 0)
	{
		num += write(1, "-", 1);
		num += ft_putnbr(-n);
	}
	else if (n >= 0 && n <= 9)
	{
		n_out = n + '0';
		num += write(1, &n_out, 1);
	}
	else
	{
		n_out = n % 10 + '0';
		n /= 10;
		num += ft_putnbr(n);
		num += write(1, &n_out, 1);
	}
	return (num);
}

int	ft_putstr(const char *s, const char c, int n)
{
	int	num;
	int	i;

	if (!s && n == 0)
		return (write(1, "(null)", 6));
	num = 0;
	if (n == 1)
		return (num += write(1, &c, 1));
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			num += write(1, &s[i], 1);
			i++;
		}
	}
	return (num);
}

int	what_identifier(char pitta, va_list agrippa)
{
	int				num;
	unsigned long	ptr;

	num = 0;
	if (pitta == 'c')
		num += ft_putstr(0, va_arg(agrippa, int), 1);
	else if (pitta == 's')
		num += ft_putstr(va_arg(agrippa, char *), 0, 0);
	else if (pitta == 'p')
	{
		ptr = va_arg(agrippa, unsigned long);
		if (!ptr)
			num += ft_puthex(ptr, pitta, 0);
		else
			num += ft_puthex(ptr, pitta, 1);
	}
	else if (pitta == 'd' || pitta == 'i')
		num += ft_putnbr(va_arg(agrippa, int));
	else if (pitta == 'u')
		num += ft_putnbr(va_arg(agrippa, unsigned int));
	else if (pitta == 'x' || pitta == 'X')
		num += ft_puthex(va_arg(agrippa, unsigned int), pitta, 2);
	else if (pitta == '%')
		num += ft_putstr(0, '%', 1);
	return (num);
}

int	ft_printf(const char *s, ...)
{
	va_list	agrippa;
	int		i;
	int		num;

	if (!s)
		return (-1);
	va_start(agrippa, s);
	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			num += ft_putstr(0, s[i], 1);
		else
		{
			i++;
			if (s[i] == '\0')
				return (va_end(agrippa), -1);
			num += what_identifier(s[i], agrippa);
		}
		i++;
	}
	return (va_end(agrippa), num);
}
