/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:24:46 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 18:19:12 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	int		i;
	int		len;

	if ((a = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	len = size;
	i = -1;
	while (++i != len + 1)
		a[i] = '\0';
	return ((void *)a);
}
