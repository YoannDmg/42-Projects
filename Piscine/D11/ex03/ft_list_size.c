/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:18:23 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/23 15:06:27 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int		ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*actuel;

	size = 0;
	actuel = begin_list;
	while (actuel != NULL)
	{
		actuel = actuel->next;
		size++;
	}
	return (size);
}
