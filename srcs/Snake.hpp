/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:54:54 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/14 10:21:09 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

#include "Game.hpp"

enum Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snake
{
	public:

		Snake( void );
		Snake( const Snake & src );
		~Snake( void );

		std::vector<Block>	getSnake( void ) const;
		void				move( void );
		void				extendSnake( void ); 
		void				checkCollision( void );
		Direction			getDirection( void ) const;
		void				setDirection( Direction dir );
		void				reset( void );

		Snake & operator=(const Snake & src);

	private:

		std::vector<Block>	_snakeBody;
		Direction			_direction;
		float				_speed;
};

#endif
