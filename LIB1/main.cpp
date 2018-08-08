/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:10:42 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/08 11:32:47 by mafernan         ###   ########.fr       */
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

	while(!game.GetWindow()->IsDone())
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
