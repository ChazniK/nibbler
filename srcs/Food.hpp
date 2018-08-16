/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:51:33 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/16 11:38:58 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_HPP
#define FOOD_HPP

# include <cstdlib>

class Food
{
	public:

		Food( void );
		Food( const Food & src );
		~Food( void );

		int		getXPos( void ) const;
		int		getYPos( void ) const;
		void	spawnFood( void );
		void	init(int width, int height);

		Food &	operator=( const Food & rhs ); 

	private:
		int		blockSize = 20;
		int		_width;
		int		_height;
		int		_xPos;
		int		_yPos;
};

#endif
