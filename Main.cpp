/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:54:07 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/30 15:03:50 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"
#include "Food.hpp"
#include <cstdlib>
#include <SFML/Graphics.hpp>

int		main(void)
{
	int		width = 600;
	int		height = 480;


	sf::RenderWindow	window(sf::VideoMode(width, height), "Snake Game");

	// //Creating the snake and food objects
	Snake snake(width / 2, height - 20);
    Food food(height / 2, 1);

	while (window.isOpen())
	{
		sf::Event		currentEvent;

		while (window.pollEvent(currentEvent))
		{
			switch(currentEvent.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			snake.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			snake.moveDown();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			snake.moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			snake.moveRight();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    	{
        	// quit...
			window.close();
    	}

		snake.update();
		food.update();
		window.clear();

		window.draw(snake.getShape());
		window.draw(food.getShape());
		window.display();
	}
	return (0);
}
