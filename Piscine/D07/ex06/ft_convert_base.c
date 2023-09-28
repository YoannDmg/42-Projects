/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:48:03 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/16 16:13:16 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}

char	*ft_calc_base(int nb, int base_t_lenght, char *base_to)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = 0;
	while (nb / i > 0)
	{
		j++;
		i = i * base_t_lenght;
	}
	str = (char*)malloc(sizeof(char) * (j + 1));
	i = 0;
	j--;
	while (j >= 0)
	{
		str[i] = base_to[(nb / ft_power(base_t_lenght, j))];
		nb = nb % ft_power(base_t_lenght, j);
		j--;
		i++;
	}
	str[i] = 0;
	return (str);
}

int		ft_to_base_dec(char *nb, char *base_f, int base_f_lenght, int nb_length)
{
	int i;
	int j;
	int k;
	int result;

	i = 0;
	j = 0;
	k = 0;
	result = 0;
	while (nb[i] != '\0')
	{
		while (base_f[k] != nb[i])
			k++;
		result = result + ft_power(base_f_lenght, nb_length - i - 1) * k;
		i++;
		k = 0;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_lenght;
	int		base_to_lenght;
	int		nbr_length;
	int		nbr_dec;
	char	*result;

	base_from_lenght = ft_strlen(base_from);
	base_to_lenght = ft_strlen(base_to);
	nbr_length = ft_strlen(nbr);
	nbr_dec = ft_to_base_dec(nbr, base_from, base_from_lenght, nbr_length);
	result = ft_calc_base(nbr_dec, base_to_lenght, base_to);
	if (result[0] == 0)
		result[0] = '0';
	return (result);
}
