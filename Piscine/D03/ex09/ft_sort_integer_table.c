/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:12:47 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/05 17:03:50 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_tri(int *tab, int size)
{
	int rand;
	int i;
	int temp;

	i = 0;
	rand = 1;
	while (rand)
	{
		rand = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				rand = 1;
			}
			i++;
		}
		size--;
	}
}

void	ft_sort_integer_table(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_tri(tab, size);
		i++;
	}
}
