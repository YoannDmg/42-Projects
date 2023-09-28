/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <cbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:53:22 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/16 17:22:08 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *str, char c)
{
	int		word;
	int		i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char		*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		wrd;
	char	**s;

	if (str)
	{
		i = 0;
		j = 0;
		wrd = ft_count_words(str, c);
		if (!(s = (char **)malloc(sizeof(s) * (ft_count_words(str, c) + 2))))
			return (NULL);
		while (str[i] == c && str[i])
			i++;
		while (j < wrd && str[i])
		{
			s[j] = ft_word(str, c, &i);
			j++;
		}
		s[j] = NULL;
		return (s);
	}
	return (NULL);
}
