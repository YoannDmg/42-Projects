/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 21:47:21 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/22 15:14:21 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list *actuel;
	t_list *precedent;
	t_list *suivant;

	precedent = NULL;
	actuel = *begin_list;
	while (actuel != NULL)
	{
		suivant = actuel->next;
		actuel->next = precedent;
		precedent = actuel;
		actuel = suivant;
	}
	*begin_list = precedent;
}
