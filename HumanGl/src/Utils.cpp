/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/06 15:19:08 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "OpenGL.hpp"	/* glGetShaderInfoLog */
#include "All.hpp"		/* all for draw_cube */
#include <iostream>		/* cerr, string */
#include <fstream>		/* ifstream */
#include <sstream>		/* stringstream */
#include <cstdlib>		/* exit */
#include <cmath>		/* round */


namespace Utils
{
	void	error_quit(const std::string &str)
	{
		std::cerr << str << std::endl;
		exit(0);
	}

	std::string	read_file(const char *filename)
	{
		std::ifstream		fs;
		std::stringstream	ss;

		fs.open(filename);
		if (!fs.is_open())
			error_quit("Cannot open source file");
		ss << fs.rdbuf();
		return (ss.str());
	}

	void		openGL_error_log(unsigned int shader, int err_code,
				const char *filename)
	{
		char	buffer[512];

		std::cerr << "[" << filename << "] shader compilation failed: [" <<
		err_code << "/1]" << std::endl;
		glGetShaderInfoLog(shader, 512, NULL, buffer);
		std::cerr << "Compilation log:" << std::endl << buffer;
		exit(0);
	}

	float	round(float f, int decimal)
	{
		float	n;

		n = (float)std::pow(10.0f, decimal);
		return (std::round(f * n) / n);
	}

	/* preset colors */
	void	draw_cube(const Matrix &model)
	{
		glUniformMatrix4fv(all.gl.uniform.matrix_model, 1, true, model.data());
		glUniform1i(all.gl.uniform.color, 0x8080ff);
		glDrawArrays(GL_TRIANGLES, 0, 3);	/* front */
		glDrawArrays(GL_TRIANGLES, 3, 3);	/* front */
		glDrawArrays(GL_TRIANGLES, 6, 3);	/* back */
		glDrawArrays(GL_TRIANGLES, 9, 3);	/* back */
		glUniform1i(all.gl.uniform.color, 0xff8080);

		glDrawArrays(GL_TRIANGLES, 12, 3);	/* left */
		glDrawArrays(GL_TRIANGLES, 15, 3);	/* left */
		glDrawArrays(GL_TRIANGLES, 18, 3);	/* right */
		glDrawArrays(GL_TRIANGLES, 21, 3);	/* right */
		glUniform1i(all.gl.uniform.color, 0x80ff80);


		glDrawArrays(GL_TRIANGLES, 24, 3);	/* bottom */
		glDrawArrays(GL_TRIANGLES, 27, 3);	/* bottom */
		glDrawArrays(GL_TRIANGLES, 30, 3);	/* top */
		glDrawArrays(GL_TRIANGLES, 33, 3);	/* top */
		// glDrawArrays(GL_TRIANGLES, 16, 3);	/* bottom */
		// glDrawArrays(GL_TRIANGLES, 20, 3);	/* top */
	}

	/* set colors */
	void	draw_cube(const Matrix &model, unsigned color)
	{
		glUniformMatrix4fv(all.gl.uniform.matrix_model, 1, true, model.data());
		glUniform1i(all.gl.uniform.color, (GLint)color);
		glDrawArrays(GL_TRIANGLES, 0, 6);	/* front */
		glDrawArrays(GL_TRIANGLES, 6, 6);	/* back */
		glDrawArrays(GL_TRIANGLES, 12, 6);	/* left */
		glDrawArrays(GL_TRIANGLES, 18, 6);	/* right */
		glDrawArrays(GL_TRIANGLES, 24, 6);	/* bottom */
		glDrawArrays(GL_TRIANGLES, 30, 6);	/* top */
	}
}