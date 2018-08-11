/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:40:47 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/11 15:02:22 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "World.hpp"
#include "Snake.hpp"

class	Game
{
	public:

		Game();
		~Game();

		void	HandleInput();
		void	Update();
		void	Render();

		sf::Time GetElapsed();
		void	RestartClock();

		Window*	GetWindow();

	private:

		Window	m_window;
		sf::Clock m_clock;
		float	m_elapsed;

		World m_world;
		Snake m_snake;

};

#endif
