/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:55:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/16 12:28:07 by ckatz            ###   ########.fr       */
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

void				Snake::Tick()
{
	if (getSnake().empty())
	{
		return;
	}
	if (_direction == Direction::NONE)
	{
		return;
	}
	move();
	checkCollision();
}

std::vector<Block>	Snake::getSnake( void ) const
{
	return _snakeBody;
}

void				Snake::move( void )
{
	for (int i = getSnake().size() - 1; i > 0; --i)
	{
		//Not sure if both x and y need to get updated or if its only the i
		_snakeBody[i].x = _snakeBody[i - 1].x;
		_snakeBody[i].y = _snakeBody[i - 1].y;
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
	if (_snakeBody.empty())
	{ 
		return; 
	}
	Block &tail_head = _snakeBody[_snakeBody.size() - 1];
	if(_snakeBody.size() > 1)
	{
		Block &tail_bone = _snakeBody[_snakeBody.size() - 2];
		if(tail_head.x == tail_bone.x)
		{
			if(tail_head.y > tail_bone.y)
			{
				_snakeBody.push_back(Block(tail_head.x, tail_head.y + 1));
			} 
			else
			{
				_snakeBody.push_back(Block(tail_head.x, tail_head.y - 1));
			}
		} 
		else if(tail_head.y == tail_bone.y)
		{
			if(tail_head.x > tail_bone.x)
			{
				_snakeBody.push_back(Block(tail_head.x + 1, tail_head.y));
			} 
			else
			{
				_snakeBody.push_back(Block(tail_head.x - 1, tail_head.y));
			}
		}
	} 
	else
	{
		if(_direction == Direction::UP)
		{
			_snakeBody.push_back(Block(tail_head.x, tail_head.y + 1));
		} 
		else if (_direction == Direction::DOWN)
		{
			_snakeBody.push_back(Block(tail_head.x, tail_head.y - 1));
		} 
		else if (_direction == Direction::LEFT)
		{
			_snakeBody.push_back(Block(tail_head.x + 1, tail_head.y));
		}
		else if (_direction == Direction::RIGHT)
		{
			_snakeBody.push_back(Block(tail_head.x - 1, tail_head.y));
		}
	}
}

void				Snake::checkCollision( void )
{
	if (_snakeBody.size() < 5)
	{ 
		return; 
	}
	Block &head = _snakeBody.front();
	for(auto itr = _snakeBody.begin() + 1; itr != _snakeBody.end(); ++itr)
	{
		if(itr->x == head.x && itr->y == head.y)
		{
			//Exit condition
			break;
		}
	}
}

Direction			Snake::getDirection( void ) const
{
	return _direction;
}

void				Snake::setDirection( Direction dir )
{
	_direction = dir;
}

void				Snake::reset( void )
{
	_snakeBody.clear();
	_snakeBody.push_back(Block(5,7));
	_snakeBody.push_back(Block(5,6));
	_snakeBody.push_back(Block(5,5));
	_snakeBody.push_back(Block(5,4));
	setDirection(Direction::NONE); // Start off still.
	_speed = 15;
}

Snake & 			Snake::operator=(const Snake & src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}
