/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:54:12 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/17 12:30:22 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	if (length < 2)
		return (0);
	i = 0;
	while (i + 1 < length && f(tab[i], tab[i + 1]) >= 0)
		i++;
	if (i + 1 >= length)
		return (1);
	i = 0;
	while (i + 1 < length && f(tab[i + 1], tab[i]) >= 0)
		i++;
	if (i + 1 >= length)
		return (1);
	return (0);
}
