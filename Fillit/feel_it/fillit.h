/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbenoit <cbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:05:48 by cbenoit           #+#    #+#             */
/*   Updated: 2018/12/06 14:00:17 by cbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE ((26 *((5 * 4) + 1)) - 1)
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./../libft/libft.h"

int		error(char *buf, int i, int j, int k);
int		main_solver(char **tab, int size_tab, int pos[]);
char	**fill_tab(char *buf, int i);
char	**convert_tab(char *buf);
void	print_solution(char **tmp, int size);
int		recur(char **a, char **tab, int size, int pos[]);
void	transfer(int a[], int b[]);
#endif
