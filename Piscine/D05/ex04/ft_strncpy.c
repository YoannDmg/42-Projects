/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:34:32 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/14 17:09:50 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int in;

	in = n;
	i = 0;
	if (n > 2147483647)
		return (0);
	while (src[i] != '\0' && n--)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < in)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
