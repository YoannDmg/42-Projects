/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/06 15:18:40 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>	/* std::string */
#include "Matrix.hpp"	/* Matrix */

namespace Utils
{
	void		error_quit(const std::string &str);
	std::string	read_file(const char *filename);
	void		openGL_error_log(unsigned int shader, int err_code,
		const char *filename);
	float		round(float f, int decimal);
	void		draw_cube(const Matrix &model);
	void		draw_cube(const Matrix &model, unsigned color);

}

#endif
