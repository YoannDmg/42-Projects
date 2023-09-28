/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:20:19 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/13 17:52:05 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		erase_mlx(t_mlx mlx)
{
	t_point		*tmp;
	t_struct	*data;

	data = NULL;
	tmp = NULL;
	while (mlx.data != NULL)
	{
		data = mlx.data;
		mlx.data = mlx.data->next;
		free(data->content);
		free(data);
	}
	while (mlx.point != NULL)
	{
		tmp = mlx.point;
		mlx.point = mlx.point->next;
		free(tmp);
	}
	mlx.data = NULL;
	mlx.point = NULL;
}

static void		erase_map(t_mlx mlx)
{
	mlx.color = COLOR_BLACK;
	draw_map(mlx, mlx.point);
}

static int		key_event(int key, t_mlx *mlx)
{
	erase_map(*mlx);
	if (key == KEY_ESC)
	{
		erase_mlx(*mlx);
		exit(0);
	}
	if (key == KEY_PAGEUP || key == KEY_PAGEDOWN)
		h_modify(mlx->point, key);
	if (key >= KEY_LEFT && key <= KEY_UP)
		move_event(mlx->point, key);
	if (key == KEY_S || key == KEY_A)
		iso(*mlx, mlx->point, key);
	if (key == KEY_Z || key == KEY_X)
		zoom(mlx->point, key);
	draw_map(*mlx, mlx->point);
	return (0);
}

int				ft_event(t_mlx mlx)
{
	draw_map(mlx, mlx.point);
	mlx_key_hook(mlx.win_ptr, key_event, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (1);
}
