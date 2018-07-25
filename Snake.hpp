/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:03:31 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/25 12:41:03 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>

class Snake
{
	public:
		
		//Declaration of constructors and destructor for Snake class
		Snake(void);
		Snake(const Snake &src);
		Snake(float startX, float startY);
		~Snake(void);

		FloatRect		getPosition(void) const;
		RectangleShape	getShape(void) const;
		void			moveUp(void);
		void			moveDown(void);
		void			moveLeft(void);
		void			moveRight(void);

		Snake operator=(Snake & rhs)

	private:

		Vector2f		_position;
		RectangleShape	_snakeShape;
		//speed in number of pixels per frame
		float			_snakeSpeed = 0.3f;
};
