/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:28:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/11 14:40:37 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRAPHICS_HPP
#define IGRAPHICS_HPP

enum KeyInput {

	UP,
	DOWN,
	LEFT,
	RIGHT,
	ESC,
	F1,
	F2,
	F3
};

class IGraphics
{
	public:

		virtual void		createWindow(void) = 0;
		virtual	void		clearWindow(void) = 0;
		virtual void		drawSnake(void) = 0;
		virtual void		drawFood(void) = 0;
		virtual void		handleInput(int key) = 0;
		virtual KeyInput	getInput(void) = 0;
		virtual int			getWidth(void) = 0;
		virtual int			getHeight(void) = 0;
		virtual void		destroyWindow(void) = 0;
		virtual 			~IGraphics(void) = 0;
};

#endif