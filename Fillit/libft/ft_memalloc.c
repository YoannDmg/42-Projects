/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:59:19 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 18:10:22 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*a;
	int		i;
	int		len;

	if ((a = (char *)malloc(sizeof(char) * size)) == 0)
		return (NULL);
	len = size;
	i = -1;
	while (++i != len)
		a[i] = 0;
	return ((void *)a);
}
