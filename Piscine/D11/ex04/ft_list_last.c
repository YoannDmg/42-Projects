/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:31:45 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/23 16:34:06 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list		*ft_list_last(t_list *begin_list)
{
	t_list	*actuel;

	if (begin_list == NULL)
		return (NULL);
	else
	{
		actuel = begin_list;
		while (actuel->next != NULL)
		{
			actuel = actuel->next;
		}
	}
	return (actuel);
}
