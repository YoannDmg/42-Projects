/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:58:50 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/14 10:50:49 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	i = 0;
	while (str[i] == to_find[i] && str[i])
		i++;
	if (to_find[i] == '\0')
		return (str);
	if (str[i] == '\0')
		return (0);
	return (ft_strstr(str + 1, to_find));
}
