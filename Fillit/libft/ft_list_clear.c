/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:48:36 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 17:31:02 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *suppr;

	while (*begin_list)
	{
		suppr = *begin_list;
		*begin_list = (*begin_list)->next;
		free(suppr);
	}
	begin_list = NULL;
}
