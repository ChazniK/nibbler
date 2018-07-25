/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:54:07 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/25 11:54:22 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <SFML/Graphics.hpp>

int		main(void)
{
	sf::RenderWindow	window(sf::VideoMode(400, 400), "Pong Game");
	sf::RectangleShape	player(sf::Vector2f(20.0f, 20.0f));
	player.setFillColor(sf::Color::Blue);

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

	/*	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.1f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}*/
		window.clear();
		window.draw(player);
		window.display();
	}
	return (0);
}
