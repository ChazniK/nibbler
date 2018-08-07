/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:40:47 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/07 16:41:23 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "Window.hpp"
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
