/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <cbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:52:23 by cbenoit           #+#    #+#             */
/*   Updated: 2018/12/10 15:44:22 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	quit(int i)
{
	if (i == 0)
		ft_putstr("error\n");
	else
		ft_putstr("usage: only one argument, try again~\n");
	return (-1);
}

int			main(int ac, char **av)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		s;
	char	**tab;
	int		pos[4];

	if (ac != 2)
		return (quit(1));
	fd = open(av[1], O_RDONLY);
	if ((s = read(fd, buf, BUFF_SIZE + 1)) > BUFF_SIZE || s == 0)
		return (quit(0));
	buf[BUFF_SIZE] = '\0';
	if (!(error(buf, 0, 0, -1)) || !(tab = convert_tab(buf)))
		return (quit(0));
	pos[0] = 0;
	pos[1] = 0;
	pos[2] = 0;
	pos[3] = 0;
	main_solver(tab, 1, pos);
	return (0);
}
