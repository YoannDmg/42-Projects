/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/12 14:51:38 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Object::Object(void) : root_part(0){ }
Object::Object(const Object &src) { *this = src; }
Object::~Object(void) { }

Object	&Object::operator=(const Object &rhs)
{
	this->model = rhs.model;
	this->root_part = rhs.root_part;
	this->dimensions = rhs.dimensions;
	this->translate = rhs.translate;
	this->rotate = rhs.rotate;
	this->color = rhs.color;
	return (*this);
}

Matrix Object::GetModel() const
{
	if (this->root_part)
	{
		return (this->root_part->GetModel() * this->model * this->translate * this->rotate );
	}
	else
	{
		return (this->model);
	}
}