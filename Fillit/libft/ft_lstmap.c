/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:27:53 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 18:08:50 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (!lst || !f)
		return (NULL);
	c = NULL;
	while (lst)
	{
		a = f(lst);
		if (!c)
		{
			c = a;
			b = c;
		}
		else
		{
			b->next = a;
			b = b->next;
		}
		lst = lst->next;
	}
	return (c);
}
