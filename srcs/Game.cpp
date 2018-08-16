/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16/49/38 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/16 11:04:03 by mafernan         ###   ########.fr       */
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


// check if string is made of numbers only
bool	Game::isDigits(const std::string & str)
{
    return (str.find_first_not_of("0123456789") == std::string::npos);
}

// get width size from user. default width set to 400
int		Game::getWidth( void )
{
	int				width = 400;
	bool			exit = false;
	std::string		line;

	std::cout << "Width size: ";
	while (getline(std::cin, line) && exit != true) 
	{
		try
		{
			if (line == "")
			{
				std::cout << "setting default width to " << width << std::endl;
				return (width);
			}
			if (isDigits(line) == true)
			{
				if (std::stoi(line) < 400 || std::stoi(line) > 1920)
					throw Error::InvalidWidth(line);
				width = std::stoi(line);
				break;
			}
			else
				throw Error::NotDigit(line);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << "Width size: ";
	}
	return (width);
}

// get height size from user. default set to 400
int		Game::getHeight( void )
{
	int				height = 400;
	bool			exit = false;
	std::string		line;

	std::cout << "Height size: ";
	while (getline(std::cin, line) && exit != true) 
	{
		try
		{
			if (line == "")
			{
				std::cout << "setting default height to " << height << std::endl;
				return (height);
			}
			if (isDigits(line) == true)
			{
				if (std::stoi(line) < 400 || std::stoi(line) > 1080)
					throw Error::InvalidHeight(line);
				height = std::stoi(line);
				break;
			}
			else
				throw Error::NotDigit(line);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << "Height size: ";
	}
	return (height);
	
}

// check if it's a valid library
bool	Game::validLibrary(std::string input)
{
	bool	res = false;

	input == "sfml" ? res = true : (input == "sdl" ?  res = true : (input == "glfw" ? res = true : res = false ));
	return res;
}

// ask user what libary to start with. default set to sfml
std::string		Game::startLibrary( void )
{
	std::string		line;	
	std::string		default_library = "sfml";
	bool			exit = false;
	
	std::cout << "Please select a library to use: sfml, sdl, glfw" << std::endl;
	std::cout << "Library: ";
	while (getline(std::cin, line) && exit != true)
	{
		try
		{
			if (line == "")
			{
				std::cout << "setting default library to " << default_library << std::endl;
				return (default_library);
			}
			if (isDigits(line) == false)
			{
				if (validLibrary(line) == true)
				{
					default_library = line;
					break ;
				}
				else
					throw Error::InvalidLibrary(line);
			}
			else
				throw Error::InvalidLibrary(line);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Library: ";
	}
	return (default_library);
}

// run the settings before hand and return the selected library
std::string		Game::windowSettings( void )
{
	_width = getWidth();
	_height = getHeight();
	return (std::string("./bin/"+startLibrary()+".so"));
}

// this will run a constant loop as long as the snake is moving
void Game::runNibbler()
{
	// get user inputs for library width and height
	(void)_score;
	const char *library = windowSettings().c_str();
	(void)library;
	this->food.init(_width, _height);
	this->food.spawnFood();
	snake.reset();
	
	try
	{
		Interface *func	= factory.createLibrary(5);
		func->Init(_width, _height);
		// while snake is moving aka hasn't touched a wall
		while (func->PollEvents())
		{
			func->Render(this->food.getXPos(), this->food.getYPos(), this->snake.getSnake());
		//	snake.move();
		//	if (func->EventHandler())
		//	{
		//		if (func->CloseWindow())
		//			break;
		//		if (func->KeyPress() == f1)
		//		{
		//			factory.deleteLibrary(func);
		//			interface *func = factory.createLibrary("sdl.so",_width, _height);
		//		}
		//
		//	}
		}
		factory.deleteLibrary(func);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
