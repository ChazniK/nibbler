/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:20:20 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/07 16:44:14 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include "Game.hpp"

int	main(int argc, char** argv)
{
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
	return (0);
}
