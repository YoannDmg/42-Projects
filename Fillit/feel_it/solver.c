/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <cbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:52:45 by cbenoit           #+#    #+#             */
/*   Updated: 2018/12/06 14:09:37 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**mallocking(char **tab, int size)
{
	int		i;
	int		j;
	char	**a;

	i = 0;
	while (tab[i][0] != 0)
		i++;
	if (size > 26 || !(a = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	a[size] = 0;
	j = -1;
	while (++j < size)
		if (!(a[j] = ft_memalloc(size + 1)))
			return (0);
	return (a);
}

void			print_solution(char **tmp, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tmp[i][j] == '\0')
				ft_putchar('.');
			else
				ft_putchar(tmp[i][j]);
		}
		ft_putchar('\n');
	}
}

char			**convert_tab(char *buf)
{
	char	**a;
	int		i[3];

	if (!(a = (char **)malloc(sizeof(char *) * (26 + 1))))
		return (NULL);
	i[0] = -1;
	i[2] = 0;
	while (++i[0] < 27)
	{
		if (!(a[i[0]] = (char *)malloc(sizeof(char) * (17))))
			return (NULL);
		i[1] = 0;
		while (buf[i[2]])
		{
			if (buf[i[2]] != '\n')
				a[i[0]][i[1]++] = buf[i[2]];
			if (buf[i[2]] == '\n' && (buf[i[2] + 1] == '\n' || !buf[i[2] + 1]))
				break ;
			i[2]++;
		}
		i[2] += 2;
		a[i[0]][i[1]] = '\0';
	}
	return (a);
}

void			transfer(int a[], int b[])
{
	a[0] = b[0];
	a[1] = b[1];
}

int				main_solver(char **tab, int size, int pos[])
{
	char	**a;
	int		i;
	int		n;

	n = 0;
	if (size == 1)
	{
		i = -1;
		while (tab[++i][0] == '.' || tab[i][0] == '#')
			n++;
		size = ft_sqrt(n * 4);
	}
	if (!(a = mallocking(tab, size)) || size < 2)
		return (0);
	if (!(recur(a, tab, size, pos)))
	{
		free(a);
		pos[0] = 0;
		pos[1] = 0;
		pos[2] = 0;
		return (main_solver(tab, size + 1, pos));
	}
	free(a);
	return (1);
}
