/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:10:42 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/11 15:16:40 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "../srcs/debug.hpp"
#include <iostream>

// this gets called in the main.cpp
extern "C" void	test(void)
{
	Debug::print("entered sfml", true);
	// Program entry point.
	Game game; // Creating our game object.
	sf::Event event;

	//game.CreateWindow();
	//while(!game.GetWindow()->IsDone())
	while (game.GetWindow()->GetRenderWindow()->isOpen())
	{
		// Game loop.
		while(game.GetWindow()->GetRenderWindow()->pollEvent(event))
			if (event.type == sf::Event::Closed)
				game.GetWindow()->GetRenderWindow()->close();
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	Debug::print( "closed sfml", true);
}

