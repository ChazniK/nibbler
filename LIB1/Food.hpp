/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:52:54 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/11 17:56:26 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_HPP
#define FOOD_HPP

#include "Game.hpp"

class Food
{
	public:

		Food(void);
		~Food(void);

		int		getXPos(void) const;
		int		getYPos(void) const;
		void	spawnFood(void);

	private:

		int		_xPos;
		int		_yPos;
};

#endif