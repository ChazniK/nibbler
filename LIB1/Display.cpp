/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:08:26 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/12 11:21:22 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/debug.hpp"
#include <SFML/Graphics.hpp>

// temporary values to work with mostly till it plugs into the main game
struct SnakeSegment {
	SnakeSegment(int x, int y) : position(x, y){}
	sf::Vector2i	position;
};

using SnakeContainer = std::vector<SnakeSegment>;

struct	Values {
	// create the apple object
	sf::CircleShape		Apple;
	sf::Vector2i		ApplePos;
	// create the wall objects
	sf::RectangleShape	Bounds[4];
	// set a permenant block size for now
	int					BlockSize = 16;
	SnakeContainer		SnakeBody;	
};

// set a background for the game
void	SetBackground(sf::RenderWindow & window)
{
	// =========== get texture ============= //
	sf::Texture		texture;
	if (!texture.loadFromFile("sprites/background.jpg"))
		Debug::print("failed to load background texture in sfml", true);
	// =========== get place blocks ============= //
	texture.setRepeated(true);
	sf::Sprite	background(texture);
	background.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
	window.draw(background);
}

// draw a wall on the sides of the window for the game border
void	CreateBorders(struct Values & val, sf::RenderWindow & window)
{
	// for every border object created (should be 4 of them)
	// set a color and "stretch" the 4 to the sides of the window to give
	// the illusion of a border
	for (int i = 0; i < 4; ++i)
	{
		val.Bounds[i].setFillColor(sf::Color(216, 216, 216));
		if (!((i + 1) % 2))
			val.Bounds[i].setSize(sf::Vector2f(window.getSize().x, val.BlockSize));
		else
			val.Bounds[i].setSize(sf::Vector2f(val.BlockSize,window.getSize().y));
		if (i < 2)
			val.Bounds[i].setPosition(0, 0);
		else
		{
			val.Bounds[i].setOrigin(val.Bounds[i].getSize());
			val.Bounds[i].setPosition(sf::Vector2f(window.getSize()));
		}
		// we draw each border onto the window now
		window.draw(val.Bounds[i]);
	}
}

// Draw the apple onto the window and set a texture
void	DrawApple(struct Values & val, sf::RenderWindow & window)
{
	sf::Texture		texture;
	if (!texture.loadFromFile("sprites/apple.png"))
	{
		Debug::print("failed to load apple texture in sfml", true);
		val.Apple.setFillColor(sf::Color::Red);
	}
	texture.setRepeated(true);
	// might have to change radius here in future
	val.Apple.setRadius(val.BlockSize - 1);
	val.Apple.setPosition(val.ApplePos.x * val.BlockSize, val.ApplePos.y * val.BlockSize);
	val.Apple.setTexture(&texture);
	window.draw(val.Apple);
}

// temporary apple function to set a random spawn point
// to be removed once implemented with the main.
void	tempAppleFunction(struct Values & val, sf::RenderWindow & window)
{
	int	maxX = (window.getSize().x / val.BlockSize) - 2;
	int	maxY = (window.getSize().y / val.BlockSize) - 2;
	val.ApplePos = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	val.Apple.setPosition(val.ApplePos.x * val.BlockSize, val.ApplePos.y * val.BlockSize);
}

// temporary function to "create a snake" to see if the snake renders properly
void	SetSnakeTemp(struct Values & val)
{
	val.SnakeBody.push_back(SnakeSegment(5,7));
	val.SnakeBody.push_back(SnakeSegment(5,6));
	val.SnakeBody.push_back(SnakeSegment(5,5));
}

// this function will render the snake and just the snake
void	CreateSnake(struct Values & val, sf::RenderWindow & window)
{
	// initilize the body object to draw here
	sf::RectangleShape Body;
	sf::Texture		headtex;
	sf::Texture		bodytex;

	// body size
	Body.setSize(sf::Vector2f(val.BlockSize, val.BlockSize - 1));

	// check if head loaded properly
	if (!headtex.loadFromFile("sprites/head.png") || !bodytex.loadFromFile("sprites/body.png"))
	{
		Debug::print("failed to load apple texture in sfml", true);
		Body.setFillColor(sf::Color::Red);
	}

	// the following is a theoritcal for loop of how I'm gonna draw the snake
	if (val.SnakeBody.size() == 0)
		Debug::print("Vector is empty please check if snake has been initialized properly", true);
	// get the head's position and draw it to it's x and y
	auto head = val.SnakeBody.begin();
	Body.setTexture(&headtex);
	Body.setPosition(head->position.x * val.BlockSize, head->position.y * val.BlockSize);
	window.draw(Body);
	// now get the rest of the body in the container to draw
	for (auto section = val.SnakeBody.begin() + 1; section != val.SnakeBody.end(); ++section)
	{
		Body.setTexture(&bodytex);
		Body.setPosition(section->position.x * val.BlockSize, section->position.y * val.BlockSize);
		window.draw(Body);
	}
}


// this will render the world in the correct order with values saved in the struct
// to be changed to accept values from a class member from the main in future
void	RenderWorld(struct Values & val, sf::RenderWindow & window)
{
	// set the background
	SetBackground(window);
	// draw the bounds to the window
	CreateBorders(val, window);
	// draw the apple to the window
	DrawApple(val, window);
	// render the snake in the right position
	CreateSnake(val, window);
}

// main will call this function from the start and send in the correct values as
// as the game progress
// temporarily using structs for values but soon to be changed to accept a class
extern "C" void Display(int width, int height, bool flag) {
	Debug::print("SFML Display here", flag);	
	sf::RenderWindow	window(sf::VideoMode(width, height, 32), "Snake!", sf::Style::Close);
	sf::Event	event;
	// call the struct here for first time and pass it where it's needed
	Values	val;
	// temporarily gonna give apple a permenant positon
	tempAppleFunction(val, window);
	// temorarily create a snake to check if it renders
	SetSnakeTemp(val);

	while (window.isOpen())
	{
		// this adds the window tab ontop to display the screen properly
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// clear the "canvas" for the next frame
		window.clear(sf::Color(163, 159, 151));
		// render the world 
		RenderWorld(val, window);
		// display the new world
		window.display();
	}
	Debug::print("Exiting SFML Display now", flag);	
}
