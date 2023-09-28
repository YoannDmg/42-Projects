/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 23:47:34 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/19 23:57:52 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "header.h"

typedef struct		s_opp
{
	char	operation;
	int		(*f)(int, int);
}					t_opp;

t_opp		g_optable[] =
{
	{'+', &ft_plus},
	{'-', &ft_moins},
	{'/', &ft_div},
	{'%', &ft_mod},
	{'*', &ft_mul}
};

#endif
