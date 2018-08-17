/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:55:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/17 17:54:23 by ckatz            ###   ########.fr       */
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

void				Snake::GetWindow(int width, int height)
{
	this->_width = width / 16;
	this->_height = height / 16;
}

bool				Snake::Tick(Food & apple)
{
	clock_t time_end;
    time_end = clock() + this->_speed * CLOCKS_PER_SEC/1000;
    while (clock() < time_end) {}
	if (getSnake().empty())
		return false;
	if (_direction == Direction::NONE)
		return true;
	if (this->getSnake()[0].x == apple.getXPos() && this->getSnake()[0].y == apple.getYPos())
	{
		extendSnake();
		this->_score += 10;
		this->_speed -= 5;
		apple.spawnFood();
	}
	move();
	checkCollision();
	return true;
}

std::vector<Block>	Snake::getSnake( void ) const
{
	return _snakeBody;
}

void				Snake::move( void )
{
	for (int i = getSnake().size() - 1; i > 0; --i)
	{
		_snakeBody[i].x = _snakeBody[i - 1].x;
		_snakeBody[i].y = _snakeBody[i - 1].y;
	}
	if (_direction == Direction::LEFT)
		--_snakeBody[0].x;
	else if (_direction == Direction::RIGHT)
		++_snakeBody[0].x;
	else if (_direction == Direction::UP)
		--_snakeBody[0].y;
	else if (_direction == Direction::DOWN)
		++_snakeBody[0].y;
}

void				Snake::extendSnake( void )
{
	if (_snakeBody.empty())
		return; 
	Block &tail_head = _snakeBody[_snakeBody.size() - 1];
	if(_snakeBody.size() > 1)
	{
		Block &tail_bone = _snakeBody[_snakeBody.size() - 2];
		if(tail_head.x == tail_bone.x)
		{
			if(tail_head.y > tail_bone.y)
				_snakeBody.push_back(Block(tail_head.x, tail_head.y + 1));
			else
				_snakeBody.push_back(Block(tail_head.x, tail_head.y - 1));
		} 
		else if(tail_head.y == tail_bone.y)
		{
			if(tail_head.x > tail_bone.x)
				_snakeBody.push_back(Block(tail_head.x + 1, tail_head.y));
			else
				_snakeBody.push_back(Block(tail_head.x - 1, tail_head.y));
		}
	} 
	else
	{
		if(_direction == Direction::UP)
			_snakeBody.push_back(Block(tail_head.x, tail_head.y + 1));
		else if (_direction == Direction::DOWN)
			_snakeBody.push_back(Block(tail_head.x, tail_head.y - 1));
		else if (_direction == Direction::LEFT)
			_snakeBody.push_back(Block(tail_head.x + 1, tail_head.y));
		else if (_direction == Direction::RIGHT)
			_snakeBody.push_back(Block(tail_head.x - 1, tail_head.y));
	}
}

void				Snake::checkCollision( void )
{
	if (_snakeBody.size() < 4)
		return; 
	Block &head = _snakeBody.front();
	for(auto itr = _snakeBody.begin() + 1; itr != _snakeBody.end(); ++itr)
	{
		if(itr->x == head.x && itr->y == head.y)
		{
			std::cout << "Final score: " << this->_score << std::endl;
			this->reset();
			break;
		}	
	}
	if (head.x <= 0 || head.y <= 0 || head.x >= _width - 1 || head.y >= _height - 1)
	{
			std::cout << "Final score: " << this->_score << std::endl;
			this->reset();
	}		
}

Direction			Snake::getDirection( void ) const
{
	return _direction;
}

// Only set direction unless it's trying to go
// in the opposite direction that it's currently moving
void				Snake::setDirection( Direction dir )
{
	if (_direction != Direction::LEFT && dir == Direction::RIGHT)
		_direction = dir;
	else if (_direction != Direction::RIGHT && dir == Direction::LEFT)
		_direction = dir;
	else if (_direction != Direction::UP && dir == Direction::DOWN)
		_direction = dir;
	else if (_direction != Direction::DOWN && dir == Direction::UP)
		_direction = dir;
	else if (dir == Direction::NONE)
		_direction = dir;
}

void				Snake::reset( void )
{
	this->_score = 0;
	this->_speed = 100;
	_snakeBody.clear();
	_snakeBody.push_back(Block(5,7));
	_snakeBody.push_back(Block(5,6));
	_snakeBody.push_back(Block(5,5));
	_snakeBody.push_back(Block(5,4));
	setDirection(Direction::NONE); // Start off still.
}

Snake & 			Snake::operator=(const Snake & src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}
