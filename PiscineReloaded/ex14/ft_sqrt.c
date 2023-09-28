/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:28:47 by ydemange          #+#    #+#             */
/*   Updated: 2018/11/19 12:29:31 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int result;

	result = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (result < 46342)
	{
		if (result * result == nb)
			return (result);
		result++;
	}
	return (0);
}
