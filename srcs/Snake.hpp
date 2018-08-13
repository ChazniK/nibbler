/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:54:54 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/13 21:43:16 by mafernan         ###   ########.fr       */
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

		std::vector<Block>	getSnake( void );
		void				move( void );
		void				extendSnake( void ); 
		void				checkCollision( void );
		Direction			getDirection( void );
		void				reset( void );

		Snake & operator=(const Snake & src);

	private:

		std::vector<Block>	_snakeBody;
		Direction			_direction;
		float				_speed;
};

#endif
