/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:58:35 by cbenoit           #+#    #+#             */
/*   Updated: 2018/11/17 12:35:16 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		*strstrbis(const char *str, const char *to_find, int *t)
{
	while (str[0] != '\0' && str[t[0]] != '\0')
	{
		if (str[t[0]] == to_find[t[1]])
		{
			t[0]++;
			t[1]++;
			if (t[1] == 1)
				t[2] = t[0];
		}
		else if (t[1] != 0 && to_find[t[1]] != '\0')
		{
			t[1] = 0;
			t[0] = t[2];
		}
		else
			t[0]++;
		if (to_find[t[1]] == '\0' && t[1] != 0)
			return ((char *)str + t[2] - 1);
	}
	return (0);
}

char			*ft_strstr(const char *str, const char *to_find)
{
	int		t[3];

	t[2] = 0;
	t[0] = 0;
	t[1] = 0;
	if (to_find[0] == 0)
		return ((char *)str);
	else
		return (strstrbis(str, to_find, t));
}
