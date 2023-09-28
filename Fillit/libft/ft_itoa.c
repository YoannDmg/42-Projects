/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:45:43 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/09 19:54:28 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	int		j;
	int		neg;
	char	*a;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = n;
	j = 2;
	neg = 0;
	itoa_neg(&n, &neg);
	while (i /= 10)
		j++;
	j += neg;
	if ((a = (char*)malloc(sizeof(char) * j)) == NULL)
		return (NULL);
	a[--j] = '\0';
	while (j--)
	{
		a[j] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		a[0] = '-';
	return (a);
}
