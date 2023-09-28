/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:51:22 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 18:13:27 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;
	int				i;

	a = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a = -n;
	}
	i = 1;
	while (a > 9)
	{
		a /= 10;
		i *= 10;
	}
	if (n < 0)
		a = -n;
	else
		a = n;
	while (i > 0)
	{
		ft_putchar_fd((a / i) + '0', fd);
		a -= ((a / i) * i);
		i /= 10;
	}
}
