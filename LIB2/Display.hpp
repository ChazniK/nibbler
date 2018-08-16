/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:06:09 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/16 13:11:55 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "../srcs/Interface.hpp"
# include "../srcs/debug.hpp"
# include <vector>
# include <SDL.h>

class Display : public Interface
{
	public:
		Display( void );
		virtual ~Display( void );

		virtual void	Init(int width, int height);
		virtual Keys	getKey( void );
		virtual void	Render( int foodX, int foodY, std::vector<Block> snake);
		virtual bool	PollEvents( void );
		virtual void	CloseWindow( void );
		virtual void	BackGround( void );

	private:
		SDL_Event			_event;
		int					_width;
		int					_height;
		SDL_Window		*	_window;
		SDL_Renderer	*	_ren;
		//sf::CircleShape		_apple;
		//sf::RectangleShape	_bounds[4];
		//int					_blockSize = 16;
};

extern "C" Interface *	CreateDisplay(void);
extern "C" void			DeleteDisplay(Display * display);

#endif
