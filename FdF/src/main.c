/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:12:00 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/14 15:53:57 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		arg_error(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr(argv[0]);
		if (argc == 1)
			ft_putendl(": missing file operand");
		else if (argc > 2)
			ft_putendl(": too much file operand");
		return (1);
	}
	else
		return (0);
}

int		main(int argc, char **argv)
{
	t_struct	*tab;
	int			fd;

	if (arg_error(argc, argv))
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr(argv[0]);
		ft_putendl(": incorrect file");
		exit(-1);
	}
	if (!(tab = get_data(fd)))
		exit(-1);
	if (!(fdf(tab)))
		exit(-1);
	close(fd);
	exit(0);
}
