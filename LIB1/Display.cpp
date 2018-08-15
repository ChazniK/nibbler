/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:08:26 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/15 22:17:21 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

// constructor
Display::Display(void) {}

// deconstructor
Display::~Display(void) {}

bool	Display::CloseWindow( void )
{
	if (this->_event.type == sf::Event::Closed)
	{
		return true;
	}
	else
		return false;
}

// get the key inputs
Keys	Display::getKey(void)
{
	if (this->_event.type == sf::Keyboard::isPressed)
	{
		int	keyCode = this->_event.key.code
		switch(keyCode)
		{
			case keyCode.Up:
				return Keys::UPA;
				break;
			case keyCode.Down:
				return Keys::DOWNA;
				break;
			case keyCode.Left:
				return Keys::LEFTA;
				break;
			case keyCode.Right:
				return Keys::RIGHTA;
				break;
			case keyCode.Escape:
				return Keys::ESC;
				break;
			case keyCode.F1
				return Keys::F1
				break;
			case keyCode.F2
				return Keys::F2
				break;
			case keyCode.F3
				return Keys::F3
				break;
			return Keys::UNKNOWN;
		}
	}
}

// get the events
bool	Display::PollEvents( void )
{
	sf::Event	event;
	Debug::print("PollEvents function", true);

	if (this->_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->_window.close();
		getKey();
		return true
	}
	else
		return false;
/*	while (this->_window.isOpen())
	{
		while (this->_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->_window.close();
		}
	}*/
}

// render the background & border
void	Display::BackGround( void )
{
	// =========== Background ============= //
	sf::Texture		texture;
	if (!texture.loadFromFile("sprites/background.jpg"))
		Debug::print("failed to load background texture in sfml", true);
	texture.setRepeated(true);
	sf::Sprite	background(texture);
	background.setTextureRect(sf::IntRect(0, 0, this->_window.getSize().x, this->_window.getSize().y));
	this->_window.draw(background);
	// =========== Border ============= //
	for (int i = 0; i < 4; ++i)
	{
		this->_bounds[i].setFillColor(sf::Color(216, 216, 216));
		if (!((i + 1) % 2))
			this->_bounds[i].setSize(sf::Vector2f(this->_window.getSize().x, this->_blockSize));
		else
			this->_bounds[i].setSize(sf::Vector2f(this->_blockSize,this->_window.getSize().y));
		if (i < 2)
			this->_bounds[i].setPosition(0, 0);
		else
		{
			this->_bounds[i].setOrigin(this->_bounds[i].getSize());
			this->_bounds[i].setPosition(sf::Vector2f(this->_window.getSize()));
		}
		this->_window.draw(this->_bounds[i]);
	}

}

// render background/apple/snake/border
void	Display::Render(int foodX, int foodY, std::vector<Block> snake)
{
	_window.create(sf::VideoMode(_width, _height, 32), "Snake", sf::Style::Close);
	this->_window.clear(sf::Color(163, 159, 151));
	// === Background === //
	BackGround();
	// ===== APPLE ===== //
	sf::Texture		texture;
	if (!texture.loadFromFile("sprites/apple.png"))
	{
		Debug::print("failed to load apple texture in sfml", true);
		_apple.setFillColor(sf::Color::Red);
	}
	texture.setRepeated(true);
	_apple.setRadius(this->_blockSize - 1);
	_apple.setPosition(foodX * this->_blockSize, foodY * this->_blockSize);
	_apple.setTexture(&texture);
	this->_window.draw(_apple);

	// ====== SNAKE ========= //
	sf::RectangleShape 	Body;
	sf::Texture			headtex;
	sf::Texture			bodytex;
	Body.setSize(sf::Vector2f(this->_blockSize, this->_blockSize - 1));
	if (!headtex.loadFromFile("sprites/head.png") || !bodytex.loadFromFile("sprites/body.png"))
	{
		Debug::print("failed to load apple texture in sfml", true);
		Body.setFillColor(sf::Color::Red);
	}
	if (snake.size() == 0)
		Debug::print("Vector is empty please check if snake has been initialized properly", true);
	auto head = snake.begin();
	Body.setTexture(&headtex);
	Body.setPosition(head->x * this->_blockSize, head->y * this->_blockSize);
	this->_window.draw(Body);
	for (auto section = snake.begin() + 1; section != snake.end(); ++section)
	{
		Body.setTexture(&bodytex);
		Body.setPosition(section->x * this->_blockSize, section->y * this->_blockSize);
		this->_window.draw(Body);
	}
	this->_window.display();
}

// initilize screen size
void	Display::Init(int width, int height)
{
	this->_width = width;
	this->_height = height;
}

// return instance of display object.
Interface * CreateDisplay( void )
{
	return new Display;
}
// delete new instance of it
void	DeleteDisplay(Display * display)
{
	delete display;
}
