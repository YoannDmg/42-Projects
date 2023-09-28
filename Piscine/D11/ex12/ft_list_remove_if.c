/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:03:22 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/23 13:32:48 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list;
	t_list *tmp;

	if (*begin_list == NULL)
		return ;
	list = *begin_list;
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		if (cmp(tmp->data, data_ref) == 0)
		{
			free(tmp);
			tmp = list;
		}
	}
}
