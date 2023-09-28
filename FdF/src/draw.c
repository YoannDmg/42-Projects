/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:54:15 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/13 18:27:28 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		choose_color(t_cor cor1, t_cor cor2, t_mlx mlx)
{
	if (mlx.color == COLOR_BLACK)
		return (mlx.color);
	if ((cor1.dh < 0 && cor2.dh < 0) || (cor1.dh == 0 && cor2.dh < 0)
			|| (cor1.dh < 0 && cor2.dh == 0))
		return (COLOR_BLUE);
	if (cor1.dh >= 10 && cor2.dh >= 10)
		return (COLOR_WHITE);
	if (((cor1.dh < 10 && cor1.dh >= 5) || (cor2.dh < 10 && cor2.dh >= 5)))
		return (COLOR_BROWN);
	return (COLOR_GREEN);
}

static int		ft_abs(int i)
{
	return (i < 0 ? -i : i);
}

static void		tracer_seg(t_cor cor1, t_cor cor2, t_mlx mlx)
{
	cor1.y -= cor1.h;
	cor2.y -= cor2.h;
	mlx.map.dx = ft_abs(cor2.x - cor1.x);
	mlx.map.dy = ft_abs(cor2.y - cor1.y);
	mlx.map.err = (mlx.map.dx > mlx.map.dy ? mlx.map.dx :
			(mlx.map.dy * -1)) / 2;
	mlx.map.sx = cor1.x < cor2.x ? 1 : -1;
	mlx.map.sy = cor1.y < cor2.y ? 1 : -1;
	while (1)
	{
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, cor1.x, cor1.y,
				choose_color(cor1, cor2, mlx));
		if (cor1.x == cor2.x && cor1.y == cor2.y)
			break ;
		if ((mlx.map.e2 = mlx.map.err) > (mlx.map.dx * -1))
		{
			mlx.map.err -= mlx.map.dy;
			cor1.x += mlx.map.sx;
		}
		if (mlx.map.e2 < mlx.map.dy)
		{
			mlx.map.err += mlx.map.dx;
			cor1.y += mlx.map.sy;
		}
	}
}

void			draw_map(t_mlx mlx, t_point *point)
{
	t_point *spoint;

	spoint = point;
	while (point->next != NULL)
	{
		if (point->cor.line == point->next->cor.line)
			tracer_seg(point->cor, point->next->cor, mlx);
		point = point->next;
	}
	point = spoint;
	while (point->cor.line == 0 && point->next != NULL)
		point = point->next;
	while (point != NULL && point->cor.line != 0)
	{
		tracer_seg(point->cor, spoint->cor, mlx);
		point = point->next;
		spoint = spoint->next;
	}
}
