/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 21:07:32 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/16 15:22:24 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *str;
	int i;

	i = 0;
	if (min >= max)
		return (0);
	if (min <= -2147483648 || max > 2147483647)
		return (0);
	str = (int*)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		str[i] = min;
		min++;
		i++;
	}
	return (str);
}
