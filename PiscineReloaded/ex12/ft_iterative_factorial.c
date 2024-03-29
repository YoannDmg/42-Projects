/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:26:09 by ydemange          #+#    #+#             */
/*   Updated: 2018/11/19 12:27:16 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;

	result = 1;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	else
	{
		while (nb > 1)
		{
			result = result * nb;
			nb--;
		}
	}
	return (result);
}
