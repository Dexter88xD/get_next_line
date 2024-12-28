/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:02:42 by sohamdan          #+#    #+#             */
/*   Updated: 2024/11/06 17:39:38 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	nbrout;

	nbr = n;
	if (nbr == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
		ft_putnbr_fd(nbr, fd);
	}
	else if (nbr >= 0 && nbr <= 9)
	{
		nbrout = nbr + '0';
		write(fd, &nbrout, 1);
	}
	else
	{
		nbrout = nbr % 10 + '0';
		nbr /= 10;
		ft_putnbr_fd(nbr, fd);
		write(fd, &nbrout, 1);
	}
}
