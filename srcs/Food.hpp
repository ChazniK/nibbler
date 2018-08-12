/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:51:33 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/12 17:44:32 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_HPP
#define FOOD_HPP

#include "Game.hpp"

class Food
{
	public:

		Food( void );
		Food( const Food & src );
		~Food( void );

		int		getXPos( void ) const;
		int		getYPos( void ) const;
		void	spawnFood( void );

		Food &	operator=( const Food & rhs ); 

	private:

		int		_xPos;
		int		_yPos;
};

#endif