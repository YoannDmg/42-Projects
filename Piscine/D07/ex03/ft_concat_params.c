/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:40:44 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/16 15:21:13 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_complet_str(int argc, char **argv, char *str)
{
	int j;
	int i;
	int a;

	i = 1;
	a = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			str[a] = argv[i][j];
			a++;
			j++;
		}
		if (i == argc - 1)
			str[a] = '\0';
		else
		{
			str[a] = '\n';
			a++;
		}
		i++;
	}
	return (str);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		taille;

	taille = 0;
	i = 1;
	while (i < argc)
	{
		taille += ft_strlen(argv[i]) + 1;
		i++;
	}
	str = (char*)malloc(taille * sizeof(char));
	return (ft_complet_str(argc, argv, str));
}
