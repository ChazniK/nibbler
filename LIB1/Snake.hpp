
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>

#include "Game.hpp"

enum	Direction{ NONE, UP, DOWN, LEFT, RIGHT };

class	Snake
{
	public:

		Snake();
		~Snake();
		// Helper methods.
		void		SetDirection(Direction l_dir);
		Direction	GetDirection();
		int			GetSpeed();
			GetPosition();
		void		Extend(); // Grow the snake.
		void		Reset(); // Reset to starting position.
		void		Move(); // Movement method.
		void		Tick(); // Update method.
	
	private:

		void				CheckCollision(); // Checking for collisions.
		std::vector<Block> _snakeBody; // Segment vector.
		int			_size; // Size of the graphics.
		Direction	_direction; // Current direction.
		int			m_speed; // Speed of the snake.
};

#endif
