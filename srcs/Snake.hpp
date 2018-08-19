/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:54:54 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/19 08:35:55 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include "debug.hpp" 
#include "Food.hpp"
#include <time.h>

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
		bool				Tick( Food & apple );
		void				reset( void );
		void				GetWindow(int width, int height);
		void				setLives(int lives);
		void				setDifficulty(int lives);
		int					getScore( void );
		int					getLives( void );

		Snake & operator=(const Snake & src);

	private:

		std::vector<Block>	_snakeBody;
		Direction			_direction;
		int					_width;
		int					_height;
		int					_score = 0;
		float				_speed;
		int					_lives = 3;
		int					_resetLives;
		int					_difficulty = 0;
};

#endif
