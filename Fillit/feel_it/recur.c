/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <cbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:52:45 by cbenoit           #+#    #+#             */
/*   Updated: 2018/12/06 14:08:09 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_valid(char **a, char **tab, int size, int pos[])
{
	int	i;
	int	n;
	int	first;
	int	xadd;
	int	yadd;

	i = -1;
	n = 0;
	while (tab[pos[2]][++i] && n < 4)
	{
		if (tab[pos[2]][i] == '#')
		{
			if (n == 0)
				first = i;
			yadd = (i / 4) - (first / 4);
			xadd = (i - ((i / 4) * 4)) - (first - ((first / 4) * 4));
			if (pos[0] + xadd < 0 || pos[1] + yadd < 0 || pos[1] + yadd > size
			- 1 || pos[0] + xadd > size - 1 || a[pos[1] + yadd][pos[0] + xadd])
				return (0);
			n++;
		}
	}
	return (1);
}

static char		**place(char **a, char **tab, int pos[])
{
	int	i;
	int	first;
	int	xadd;
	int	yadd;

	i = -1;
	first = -1;
	while (tab[pos[2]][++i])
	{
		if (tab[pos[2]][i] == '#')
		{
			if (first == -1)
				first = i;
			yadd = (i / 4) - (first / 4);
			xadd = (i - ((i / 4) * 4)) - (first - ((first / 4) * 4));
			a[pos[1] + yadd][pos[0] + xadd] = pos[2] + 65;
		}
	}
	return (a);
}

static char		**replace(char **a, int pos[], int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (a[i][j] == pos[2] + 65)
				a[i][j] = '\0';
	}
	return (a);
}

static int		*diff_pos(int pos[], int size, int init)
{
	if (init)
	{
		pos[0] = 0;
		pos[1] = 0;
		pos[2] += 1;
	}
	else if (pos[0] < size - 1)
		pos[0] += 1;
	else if (pos[1] < size - 1)
	{
		pos[0] = 0;
		pos[1] += 1;
	}
	else
		return (0);
	return (pos);
}

int				recur(char **a, char **tab, int size, int *pos)
{
	int		pose[2];

	while (!(is_valid(a, tab, size, pos)))
		if (!(diff_pos(pos, size, 0)))
			return (0);
	a = place(a, tab, pos);
	transfer(pose, pos);
	pos = diff_pos(pos, size, 1);
	while (tab[pos[2]][0] && !(recur(a, tab, size, pos)))
	{
		pos[2] -= 1;
		a = replace(a, pos, size);
		transfer(pos, pose);
		if (!(diff_pos(pos, size, 0)))
			return (0);
		while (!(is_valid(a, tab, size, pos)))
			if (!(diff_pos(pos, size, 0)))
				return (0);
		a = place(a, tab, pos);
		transfer(pose, pos);
		pos = diff_pos(pos, size, 1);
	}
	if (pos[3] == 0 && pos[3]++ == 0)
		print_solution(a, size);
	return (1);
}
