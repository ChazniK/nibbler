/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SfmlGraphics.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:03:33 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/11 17:20:46 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_GRAPHICS_HPP
#define SFML_GRAPHICS_HPP

#include "IGraphics.hpp"
#include "Game.hpp"

class SfmlGraphics: IGraphics
{
		virtual void		createWindow(void);
		virtual	void		displayToWindow(Food &food);
		virtual void		handleInput(int key);
		virtual KeyInput	getInput(void) const;
		virtual int			getWidth(void) const;
		virtual int			getHeight(void) const;
		virtual void		destroyWindow(void);

};

#endif