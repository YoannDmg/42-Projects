/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:53:03 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/13 17:51:16 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "mlx.h"

# define KEY_ESC		53
# define KEY_Z			6
# define KEY_X			7
# define KEY_PAGEUP		116
# define KEY_PAGEDOWN	121
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_A			0
# define KEY_S			1
# define COLOR_WHITE	16777215
# define COLOR_BLUE		3342591
# define COLOR_GREEN	25600
# define COLOR_BROWN	13789470
# define COLOR_BLACK	0

typedef struct			s_map
{
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
}						t_map;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					color;
	int					space;
	struct s_point		*point;
	struct s_struct		*data;
	struct s_map		map;
}						t_mlx;

typedef struct			s_struct
{
	int					*content;
	int					len;
	struct s_struct		*next;
}						t_struct;

typedef struct			s_cor
{
	int					dh;
	int					mark;
	int					x;
	int					y;
	int					h;
	int					line;
}						t_cor;

typedef struct			s_point
{
	struct s_cor		cor;
	struct s_point		*next;
}						t_point;

void					draw_map(t_mlx mlx, t_point *point);
void					h_modify(t_point *index, int key);
void					move_event(t_point *point, int key);
void					iso(t_mlx mlx, t_point *index, int key);
void					zoom(t_point *index, int key);
int						fdf(t_struct *tab);
int						ft_event(t_mlx mlx);
t_struct				*get_data(int fd);

#endif
