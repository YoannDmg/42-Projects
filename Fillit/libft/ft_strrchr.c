/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:18:41 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/11 13:31:15 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*data;

	data = NULL;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			data = (char *)s + i;
	}
	if (c == 0)
		return ((char *)s + i);
	return (data);
}
