/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SfmlGraphics.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:02:45 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/11 15:02:58 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <iostream>

/*extern "C" void	test(void)
{
	std::cout << "start" << std::endl;
	// Program entry point.
	Game game; // Creating our game object.

	while(!game.GetWindow()->IsDone())
	{
		// Game loop.
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	std::cout << "closed" << std::endl;
}*/

int		main(void)
{
	std::cout << "start" << std::endl;
	// Program entry point.
	Game game; // Creating our game object.
	sf::Window window(sf::VideoMode(800, 600), "Snake");

	while(1)
	{
		// Game loop.
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	std::cout << "closed" << std::endl;
	return (0);
}
