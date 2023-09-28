/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:41:25 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/20 11:58:36 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../includes/struct.h"

int		ft_calcul(int nb1, char *op, int nb2)
{
	int i;

	i = 0;
	if (*op == '+' || *op == '-' || *op == '*' || *op == '/' || *op == '%')
	{
		while (i < 5)
		{
			if (g_optable[i].operation == *op)
			{
				return (g_optable[i].f(nb1, nb2));
			}
			i++;
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	*op;
	int		nbr1;
	int		nbr2;

	if (argc == 4)
	{
		op = argv[2];
		nbr1 = ft_atoi(argv[1]);
		nbr2 = ft_atoi(argv[3]);
		if (nbr2 <= 0 && *op == '/')
		{
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		if (nbr2 <= 0 && *op == '%')
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		ft_putnbr(ft_calcul(nbr1, op, nbr2));
		ft_putchar('\n');
	}
	else
		return (0);
}
