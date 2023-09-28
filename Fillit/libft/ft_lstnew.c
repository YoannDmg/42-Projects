/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:11:54 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 18:09:18 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *b;

	if ((b = (t_list *)malloc(sizeof(t_list))) == 0)
		return (NULL);
	if (content == NULL)
	{
		b->content_size = 0;
		b->content = NULL;
	}
	else
	{
		if ((b->content = (t_list *)ft_memalloc(content_size)) == 0)
			return (NULL);
		if ((b->content = (t_list *)ft_memcpy(b->content,
		content, content_size)) == 0)
			return (NULL);
		b->content_size = content_size;
	}
	b->next = NULL;
	return (b);
}
