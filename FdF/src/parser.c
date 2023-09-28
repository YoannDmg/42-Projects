/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:10:48 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/13 17:52:32 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			ft_del(char **str, char **line)
{
	int			i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	ft_strdel(line);
}

static t_struct		*ft_get_elem(char **tab)
{
	t_struct	*data;
	int			len;
	int			i;

	i = -1;
	len = 0;
	data = NULL;
	while (tab[len] != 0)
		len++;
	if (!(data = malloc(sizeof(t_struct))))
		return (NULL);
	data->len = len;
	if (!(data->content = malloc(sizeof(int) * len + 1)))
		return (NULL);
	while (++i != len)
		data->content[i] = ft_atoi(tab[i]);
	data->content[i] = '\0';
	data->next = NULL;
	return (data);
}

t_struct			*get_data(int fd)
{
	t_struct	*slist;
	t_struct	*data;
	char		*line;
	char		**tmp;

	data = NULL;
	slist = NULL;
	while ((ft_get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		if (slist == NULL)
		{
			if (!(slist = ft_get_elem(tmp)))
				return (NULL);
			data = slist;
		}
		else
		{
			if (!(data->next = ft_get_elem(tmp)))
				return (NULL);
			data = data->next;
		}
		ft_del(tmp, &line);
	}
	return (slist);
}
