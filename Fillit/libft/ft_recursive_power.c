/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:26:53 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/17 12:32:52 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power < 1)
	{
		if (power == 0)
			return (1);
		else
			return (0);
	}
	else if (power != 1 && power < 20)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
