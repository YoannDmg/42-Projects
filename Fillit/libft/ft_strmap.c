/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:50:24 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/14 13:42:17 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*a;
	int		i;

	if (s && f)
	{
		i = 0;
		while (s[i])
			i++;
		if ((a = (char *)malloc(sizeof(char) * (i + 1))) == 0)
			return (NULL);
		i = -1;
		while (s[++i])
			a[i] = f(s[i]);
		a[i] = '\0';
		return (a);
	}
	return (0);
}
