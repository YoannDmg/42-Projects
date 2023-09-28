/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:39:35 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 18:11:47 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;
	int			len;

	len = n;
	i = -1;
	d = dest;
	s = src;
	while (++i != len)
	{
		if (!s[i])
			d[i] = 0;
		else
			d[i] = s[i];
	}
	return (dest);
}
