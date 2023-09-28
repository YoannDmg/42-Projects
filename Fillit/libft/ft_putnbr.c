/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 10:16:50 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 18:13:20 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	a;
	int				i;

	a = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		a = -nb;
	}
	i = 1;
	while (a > 9)
	{
		a /= 10;
		i *= 10;
	}
	if (nb < 0)
		a = -nb;
	else
		a = nb;
	while (i > 0)
	{
		ft_putchar((a / i) + '0');
		a -= ((a / i) * i);
		i /= 10;
	}
}