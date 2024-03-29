/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:06:09 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/19 11:29:30 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "../srcs/Interface.hpp"
# include "../srcs/Error.hpp"
# include <vector>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>

class Display : public Interface
{
	public:
		Display( void );
		Display (const Display & src);
		virtual ~Display( void );

		virtual void	Init(int width, int height);
		virtual Keys	getKey( void );
		virtual Keys	getKey2( void );
		virtual void	Render( int foodX, int foodY, int type, std::vector<Block> snake, std::vector<Block> snake2, int set);
		virtual bool	PollEvents( void );

		Display & operator=( const Display & rhs);

	private:
		void				secondSnake(std::vector<Block> snake);
		sf::SoundBuffer		_buffer;
		sf::Sound			_sound;
		sf::Event			_event;
		int					_width;
		int					_height;
		sf::RenderWindow	_window;
		sf::CircleShape		_apple;
		sf::RectangleShape	_bounds[4];
		int					_blockSize = 16;
		virtual void				BackGround( void );
		sf::RectangleShape 	Body;
		sf::Texture			headtex;
		sf::Texture			bodytex;
};

extern "C" Interface *	CreateDisplay(void);
extern "C" void			DeleteDisplay(Display * display);

#endif
