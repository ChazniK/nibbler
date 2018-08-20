/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:06:09 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/20 17:17:23 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "../srcs/Interface.hpp"
# include <vector>
# include <glfw3.h>

typedef struct FPoints {
	float x0;
	float x1;
	float y0;
	float y1;
} Points;

class Display : public Interface
{
	public:
		Display( void );
		Display ( const Display & src);
		virtual ~Display( void );

		virtual void	Init(int width, int height);
		virtual Keys	getKey( void );
		virtual Keys	getKey2( void );
		virtual void	Render( int foodX, int foodY, int type, std::vector<Block> snake, std::vector<Block> snake2, int set);
		virtual bool	PollEvents( void );

		Display & operator=( const Display & rhs);

	private:
		int					_width;
		int					_height;
		Points	food;
		Points	body;
		Points	bg;
		GLFWwindow			*_window;
		Points				getPoints(int x, int y);
		void				secondSnake(std::vector<Block> snake);
};

extern "C" Interface *	CreateDisplay(void);
extern "C" void			DeleteDisplay(Display * display);

#endif
