/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:20:29 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/20 22:19:03 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *actuel;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		actuel = *begin_list;
		while (actuel->next != NULL)
		{
			actuel = actuel->next;
		}
		actuel->next = ft_create_elem(data);
	}
}
