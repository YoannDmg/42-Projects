/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:23:32 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/14 14:08:36 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int i;
	int b;

	b = n;
	i = 0;
	while (src[i] != '\0' && i < b)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < b)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
