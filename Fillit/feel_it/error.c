/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <cbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:52:16 by cbenoit           #+#    #+#             */
/*   Updated: 2018/12/06 14:04:46 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid(char *buf, int d)
{
	int i;
	int c;

	i = -1;
	c = 0;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			d++;
			if (buf[i - 1] && buf[i - 5] == '#')
				c++;
			if (buf[i - 1] && buf[i - 1] == '#')
				c++;
			if (buf[i + 1] && buf[i + 1] == '#')
				c++;
			if (buf[i + 5] && buf[i + 5] == '#')
				c++;
		}
	}
	free(buf);
	if (c < 6 || d != 4)
		return (0);
	return (1);
}

int			error(char *buf, int i, int j, int k)
{
	i = -1;
	while (buf[++i])
	{
		k++;
		if (buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (i > 0 && (i - j) % 20 == 0 && buf[i] == '\n' && (buf[i + 1] == '.'
		|| buf[i + 1] == '#' || !buf[i]) && ++j > -1 && i++ > -1)
		{
			k = 0;
			if (!(valid(ft_strsub(buf, i - 21, i - ((j - 1) * 20) - j), 0)))
				return (0);
		}
		else if ((i > 0 && (i - j) % 20 == 0) || (k < 4 && buf[i] == '\n'))
			return (0);
		if (k == 4)
			k = -1;
	}
	if ((i - j) % 20 != 0 || !(valid(ft_strsub(buf, i - 20,
	i - ((j - 1) * 20) - j), 0)))
		return (0);
	return (1);
}
