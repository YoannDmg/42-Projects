/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:47:48 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 18:06:50 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list	*begin_list;
	int		i;

	if (ac > 0)
	{
		i = -1;
		begin_list = ft_create_elem(av[++i]);
		while (av[++i])
			ft_list_push_front(&begin_list, av[i]);
		return (begin_list);
	}
	else
		return (NULL);
}
