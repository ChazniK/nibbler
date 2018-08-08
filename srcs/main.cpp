/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:04:59 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/08 08:12:24 by ckatz            ###   ########.fr       */
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