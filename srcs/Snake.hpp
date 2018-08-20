/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:54:54 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/20 16:51:19 by ckatz            ###   ########.fr       */
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
		std::vector<Block>	getSnake2( void ) const;
		void				move( void );
		void				extendSnake( int set ); 
		void				checkCollision( void );
		Direction			getDirection( void ) const;
		Direction			getDirection2( void ) const;
		void				setDirection( Direction dir );
		void				setDirection2( Direction dir );
		bool				Tick( Food & apple );
		void				reset( void );
		void				GetWindow(int width, int height);
		void				setLives(int lives);
		void				setDifficulty(int lives);
		void				setMultiplayer( void );
		int					getScore( void );
		int					getLives( void );

		Snake & operator=(const Snake & src);

	private:

		std::vector<Block>	_snakeBody;
		std::vector<Block>	_snakeBody2;
		Direction			_direction;
		Direction			_direction2;
		int					_width;
		int					_height;
		int					_score = 0;
		float				_speed;
		int					_lives = 3;
		int					_lives2 = 3;
		int					_resetLives;
		int					_difficulty = 0;
		int					_player = 1;
};

#endif
