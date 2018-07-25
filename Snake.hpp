/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:03:31 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/25 18:37:38 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>

class Snake
{
	public:
		
		//Declaration of constructors and destructor for Snake class
		Snake(void);
		Snake(const Snake & src);
		Snake(float startX, float startY);
		~Snake(void);

		sf::FloatRect		getPosition(void) const;
		sf::RectangleShape	getShape(void) const;
		void				moveUp(void);
		void				moveDown(void);
		void				moveLeft(void);
		void				moveRight(void);
		void				update(void);

		Snake operator=(Snake & rhs);

	private:

		sf::Vector2f		_position;
		sf::RectangleShape	_snakeShape;
		//speed in number of pixels per frame
		float				_snakeSpeed = 0.3f;
};
