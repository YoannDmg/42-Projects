/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:11:22 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/10 17:20:20 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	dlen;
	char	*d;
	char	*s;

	if (!(d = (char *)ft_memchr(dst, '\0', size)))
		return (size + ft_strlen(src));
	d = (char *)dst;
	s = (char *)src;
	dlen = ft_strlen(dst);
	len = dlen + ft_strlen(s);
	d += dlen;
	while (dlen++ < size - 1 && *s)
		*d++ = *s++;
	*d = '\0';
	return (len);
}
