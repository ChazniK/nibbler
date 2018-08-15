/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:06:09 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/15 20:56:12 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "../srcs/Interface.hpp"
# include "../srcs/debug.hpp"
# include <vector>
# include <SFML/Graphics.hpp>

class Display : public Interface
{
	public:
		Display( void );
		virtual ~Display( void );

		virtual void	Init(int width, int height);
		virtual Keys	getKey( void );
		virtual void	Render( int foodX, int foodY, std::vector<Block> snake);
		virtual bool	PollEvents( void );
		virtual bool	CloseWindow( void );
		virtual void	BackGround( void );

	private:
		int					_width;
		int					_height;
		sf::Event			_event;
		sf::RenderWindow	_window;
		sf::CircleShape		_apple;
		sf::RectangleShape	_bounds[4];
		int					_blockSize;
};

extern "C" Interface *	CreateDisplay(void);
extern "C" void			DeleteDisplay(Display * display);

#endif
