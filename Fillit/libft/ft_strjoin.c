/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:11:37 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/14 13:40:24 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*a;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		while (s1[i])
			i++;
		while (s2[j])
			j++;
		if ((a = (char *)malloc(sizeof(char) * (i + j + 1))) == 0)
			return (NULL);
		i = -1;
		j = -1;
		while (s1[++i])
			a[i] = s1[i];
		while (s2[++j])
			a[i + j] = s2[j];
		a[i + j] = '\0';
		return (a);
	}
	return (0);
}
