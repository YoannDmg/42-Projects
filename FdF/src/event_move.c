/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:42:02 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/13 18:31:04 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_event(t_point *index, int key)
{
	while (index != NULL)
	{
		if (key == KEY_UP)
			index->cor.y -= 40;
		if (key == KEY_DOWN)
			index->cor.y += 40;
		if (key == KEY_LEFT)
			index->cor.x -= 40;
		if (key == KEY_RIGHT)
			index->cor.x += 40;
		index = index->next;
	}
}

void	h_modify(t_point *index, int key)
{
	while (index != NULL)
	{
		if (index->cor.mark == 1)
			index->cor.h += key == KEY_PAGEUP ? +index->cor.dh :
				-(index->cor.dh);
		if (index->cor.mark == -1)
			index->cor.h += key == KEY_PAGEUP ? +index->cor.dh :
				-(index->cor.dh);
		index = index->next;
	}
}

void	iso(t_mlx mlx, t_point *index, int key)
{
	while (index != NULL)
	{
		index->cor.y += key == KEY_A ? (mlx.space) : -(mlx.space);
		index->cor.x -= key == KEY_A ? (mlx.space * index->cor.line / 2) :
		-(mlx.space * index->cor.line / 2);
		index = index->next;
	}
}

void	zoom(t_point *index, int key)
{
	while (index != NULL)
	{
		index->cor.x += key == KEY_Z ? (index->cor.x * 0.2) :
			(index->cor.x * -0.2);
		index->cor.y += key == KEY_Z ? (index->cor.y * 0.2) :
			(index->cor.y * -0.2);
		index = index->next;
	}
}
