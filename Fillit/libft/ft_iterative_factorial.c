/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:16:15 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/17 12:30:56 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;

	if (nb == 0)
		return (1);
	else if (nb > 12 || nb < 0)
		return (0);
	else
	{
		res = nb;
		while (--nb > 0)
			res *= nb;
		return (res);
	}
}
