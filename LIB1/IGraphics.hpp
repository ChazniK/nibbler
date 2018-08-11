/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:28:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/11 15:55:55 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRAPHICS_HPP
#define IGRAPHICS_HPP

#include "Food.hpp"

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
		virtual	void		displayToWindow(Food &food) = 0;
		virtual void		handleInput(int key) = 0;
		virtual KeyInput	getInput(void) const = 0;
		virtual int			getWidth(void) const = 0;
		virtual int			getHeight(void) const = 0;
		virtual void		destroyWindow(void) = 0;

		virtual 			~IGraphics(void) {}
};

#endif