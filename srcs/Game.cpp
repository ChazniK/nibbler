/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:49:38 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/19 11:31:55 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() {}

Game::Game(Game const & src)
{
	*this = src;	
}

Game::~Game() {}

Game & Game::operator=(Game const & src) 
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

// this will run a constant loop as long as the snake is moving
void Game::runNibbler()
{
	Display display;
	int		set = -1;

	Interface *func;

	set = display.menu();
	if (set != 0)
	{
		if (set == 2)
			snake.setMultiplayer();
		this->_width = display.screenWidth();
		this->_height = display.screenHeight();
		this->food.init(this->_width, this->_height);
		this->food.spawnFood();
		snake.GetWindow(this->_width, this->_height);
		snake.reset();
		snake.setLives(display.getLives());
		snake.setDifficulty(display.getLevel());

		try
		{
			func = factory.createLibrary(display.getLibrary(), this->_width, this->_height);
			// while snake is moving aka hasn't touched a wall
			while (snake.Tick(this->food))
			{
				// ======================= added these =================== //
				display.reset();
				display.update(snake.getScore(), snake.getLives());
				display.print();
				// ===================  ^^ added these ^^ ================ //
				func->Render(this->food.getXPos(), this->food.getYPos(), this->food.getType(), this->snake.getSnake() ,this->snake.getSnake2(), set);
				if (func->PollEvents() == false)
					break;
				if (func->getKey() == Keys::F1 || func->getKey() == Keys::F2 || func->getKey() == Keys::F3)
					func = factory.createLibrary(func->getKey(), this->_width, this->_height);
				if (func->getKey() == Keys::ESC)
					break;
				if (func->getKey() == Keys::UPA)
					snake.setDirection(Direction::UP);
				if (func->getKey() == Keys::DOWNA)
					snake.setDirection(Direction::DOWN);
				if (func->getKey() == Keys::LEFTA)
					snake.setDirection(Direction::LEFT);
				if (func->getKey() == Keys::RIGHTA)
					snake.setDirection(Direction::RIGHT);
				// player two control
				if (set == 2)
				{
					if (func->getKey2() == Keys::KEYW)
						snake.setDirection2(Direction::UP);
					if (func->getKey2() == Keys::KEYS)
						snake.setDirection2(Direction::DOWN);
					if (func->getKey2() == Keys::KEYA)
						snake.setDirection2(Direction::LEFT);
					if (func->getKey2() == Keys::KEYD)
						snake.setDirection2(Direction::RIGHT);
				}
			}
			factory.deleteLibrary(func);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
