/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:03:27 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/22 22:08:32 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)(void *, void *))
{
	t_list *list;

	list = begin_list;
	if (begin_list == NULL)
		return ;
	while (list != NULL)
	{
		if (cmp(list->data, data_ref) == 0)
			f(list->data);
		list = list->next;
	}
}
