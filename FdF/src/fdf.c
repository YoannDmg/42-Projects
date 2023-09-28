/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:51:20 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/13 18:36:30 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_cor		init(int x, int y, int line)
{
	t_cor		cor;

	cor.x = x;
	cor.y = y;
	cor.line = line;
	return (cor);
}

static t_point		*ft_get_cor(t_mlx mlx, t_cor cor, int i)
{
	t_point		*point;

	point = NULL;
	if (!(point = malloc(sizeof(t_point))))
		return (NULL);
	cor.h = mlx.data->content[i];
	cor.dh = mlx.data->content[i];
	if (cor.h == 0)
		cor.mark = 0;
	cor.mark = cor.h > 0 ? 1 : -1;
	point->cor = cor;
	point->next = NULL;
	return (point);
}

static t_point		*add_to_list(t_mlx mlx, t_cor cor, int i, t_point *spoint)
{
	t_point		*point;

	point = spoint;
	if (spoint == NULL)
	{
		if (!(spoint = ft_get_cor(mlx, cor, i)))
			return (NULL);
		point = spoint;
	}
	else
	{
		while (point->next != NULL)
			point = point->next;
		if (!(point->next = ft_get_cor(mlx, cor, i)))
			return (NULL);
		point = point->next;
	}
	return (spoint);
}

static t_point		*map(t_mlx mlx, int i)
{
	t_point		*spoint;
	t_cor		cor;
	int			line;

	line = 0;
	spoint = NULL;
	cor = init(750, 250, line);
	while (mlx.data != NULL)
	{
		if (!(spoint = add_to_list(mlx, cor, i, spoint)))
			return (NULL);
		cor.x += mlx.space;
		cor.y += mlx.space;
		if (++i == mlx.data->len)
		{
			line++;
			cor = init(750, 250, line);
			cor.y += (mlx.space * line);
			cor.x -= (mlx.space * line);
			mlx.data = mlx.data->next;
			i = 0;
		}
	}
	return (spoint);
}

int					fdf(t_struct *tab)
{
	t_mlx		mlx;
	t_point		*point;

	point = NULL;
	mlx.data = tab;
	mlx.space = mlx.data->len >= 40 ? 10 : 20;
	if (mlx.data->len >= 100)
		mlx.space = 5;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 2560, 1400, "fdf");
	if (!(point = map(mlx, 0)))
		return (-1);
	mlx.point = point;
	return (ft_event(mlx));
}
