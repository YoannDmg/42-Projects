/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 04:24:49 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 14:59:58 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int i;
	int ibis;

	i = 0;
	ibis = 0;
	while (dest[i] != '\0')
		i++;
	while (src[ibis] != '\0' && nb > 0)
	{
		dest[i + ibis] = src[ibis];
		ibis++;
		nb--;
	}
	dest[i + ibis] = '\0';
	return (dest);
}
