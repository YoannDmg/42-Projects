/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 00:22:44 by ydemange          #+#    #+#             */
/*   Updated: 2018/08/14 18:43:01 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int isrc;
	unsigned int idest;
	unsigned int result;

	idest = 0;
	isrc = 0;
	result = 0;
	while (dest[idest] != '\0')
		idest++;
	while (src[result] != '\0')
		result++;
	if (size <= idest)
		result = result + size;
	else
		result = result + idest;
	while (src[isrc] != '\0' && (idest + 1) < size)
	{
		dest[idest] = src[isrc];
		isrc++;
		idest++;
	}
	dest[idest] = '\0';
	return (result);
}
