/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:13:24 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/17 12:34:54 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	a;
	int		countmax;
	int		countmin;

	countmin = -1;
	countmax = 0;
	while (str[countmax])
		countmax++;
	while (--countmax / 2 >= ++countmin)
	{
		a = str[countmin];
		str[countmin] = str[countmax];
		str[countmax] = a;
	}
	return (str);
}
