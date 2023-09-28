/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:14:37 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/17 12:32:59 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int count;
	int out;
	int change;

	size = 2;
	out = 0;
	while (out++ == 0)
	{
		count = -1;
		while (tab[++count] && tab[count + 1])
		{
			if (tab[count] > tab[count + 1])
			{
				out = 0;
				change = tab[count];
				tab[count] = tab[count + 1];
				tab[count + 1] = change;
			}
		}
	}
}
