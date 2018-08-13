/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:55:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/13 16:08:04 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake( void )
{

}

Snake::Snake( const Snake & src )
{
	*this = src;
	return;
}

Snake::~Snake( void )
{

}

std::vector<Block>	Snake::getSnake( void )
{
	return _snakeBody;
}

void				Snake::move( void )
{
	for (int i = getSnake().size() - 1; i > 0; --i)
	{
		_snakeBody[i] = _snakeBody[i - 1];
	}
	if (_direction == Direction::LEFT)
	{
		--_snakeBody[0].x;
	}
	else if (_direction == Direction::RIGHT)
	{
		++_snakeBody[0].x;
	}
	else if (_direction == Direction::UP)
	{
		--_snakeBody[0].y;
	}
	else if (_direction == Direction::DOWN)
	{
		++_snakeBody[0].y;
	}
}

void				Snake::extendSnake( void )
{
	
}

void				Snake::checkCollision( void )
{

}

Direction			Snake::getDirection( void )
{

}

Snake & 			Snake::operator=(const Snake & src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}