/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:03:50 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/25 12:41:10 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake(void)
{

}

Snake::Snake(float startX, float, startY)
{

}

Snake::~Snake(void)
{

}

FloatRect	Snake::getPosition(void) const
{

}

RectangleShape	Snake::getShape(void) const
{
	return this->_snakeShape;
}

void	Snake::moveUp(void)
{

}

void	Snake::moveDown(void)
{

}


void	Snake::moveLeft(void)
{

}

void	Snake::moveRight(void)
{

}

Snake	Snake::operator=(Snake & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
}
