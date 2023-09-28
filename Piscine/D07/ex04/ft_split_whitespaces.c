/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:12:08 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/16 16:14:06 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_word(char *str)
{
	int i;
	int result;

	result = 0;
	i = 0;
	if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		result = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
			if (str[i] != '\0')
				result++;
			else
			{
				return (result);
			}
		}
		i++;
	}
	return (result);
}

int		count_letters(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		next_word(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	char	**index;
	int		i;
	int		j;
	int		a;

	a = 0;
	i = 0;
	index = (char**)malloc(sizeof(char*) * count_word(str) + 1);
	while (i < count_word(str))
	{
		j = 0;
		a = next_word(str, a);
		index[i] = (char*)malloc(sizeof(char) * count_letters(str + a) + 1);
		while (str[a] != '\0' && str[a] != ' ' &&
				str[a] != '\t' && str[a] != '\n')
		{
			index[i][j] = str[a];
			j++;
			a++;
		}
		index[i][j] = '\0';
		i++;
	}
	index[i] = 0;
	return (index);
}
