/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:55:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/13 21:50:56 by mafernan         ###   ########.fr       */
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
	if (_snakeBody.empty())
	{ 
		return; 
	}
	std::vector<Block> &tail_head = _snakeBody[_snakeBody.size() - 1];
	if(_snakeBody.size() > 1)
	{
		std::vector<Block> &tail_bone = _snakeBody[_snakeBody.size() - 2];
		if(tail_head..x == tail_bone.position.x)
		{
			if(tail_head.position.y > tail_bone.position.y)
			{
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
			} 
			else
			{
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
			}
		} 
		else if(tail_head.position.y == tail_bone.position.y)
		{
			if(tail_head.position.x > tail_bone.position.x)
			{
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
			} 
			else
			{
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
			}
		}
	} 
	else
	{
		if(m_dir == Direction::Up)
		{
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
		} 
		else if (m_dir == Direction::Down)
		{
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		} 
		else if (m_dir == Direction::Left)
		{
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
		}
		else if (m_dir == Direction::Right)
		{
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
	}
}

void				Snake::checkCollision( void )
{
	if (m_snakeBody.size() < 5)
	{ 
		return; 
	}
	SnakeSegment& head = m_snakeBody.front();
	for(auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
	{
		if(itr->position == head.position)
		{
			int segments = m_snakeBody.end() - itr;
			//Exit condition
			break;
		}
	}
}

Direction			Snake::getDirection( void )
{
	return _direction;
}


void				Snake::Reset( void )
{
	m_snakeBody.clear();
	m_snakeBody.push_back(SnakeSegment(5,7));
	m_snakeBody.push_back(SnakeSegment(5,6));
	m_snakeBody.push_back(SnakeSegment(5,5));
	SetDirection(Direction::None); // Start off still.
	m_speed = 15;
}

Snake & 			Snake::operator=(const Snake & src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}
