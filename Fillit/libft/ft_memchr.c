/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:50:19 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/11 12:52:29 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*a;
	unsigned char		d;

	d = (unsigned char)c;
	a = (unsigned const char *)s;
	i = -1;
	while (++i != n)
		if (a[i] == d)
			return ((void *)a + i);
	return (NULL);
}
