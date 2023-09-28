/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:29:46 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/17 12:30:15 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int c;

	c = 3;
	if (nb == 0 || nb == 1 || nb < 0)
		return (0);
	else if (nb == 2)
		return (1);
	else if (nb % 2 == 0)
		return (0);
	while (c < nb)
	{
		if (nb == (nb / c) * c)
			return (0);
		c += 2;
	}
	return (1);
}