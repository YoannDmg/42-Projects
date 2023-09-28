/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:10:54 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/21 12:36:36 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_crois(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_decrois(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (length == 0)
		return (1);
	if (ft_is_crois(tab, length, f) == 1)
		return (1);
	else if (ft_is_decrois(tab, length, f) == 1)
		return (1);
	else
		return (0);
}
