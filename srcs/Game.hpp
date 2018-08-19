/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:49:38 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/19 07:42:51 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GAME_HPP
# define	GAME_HPP

# include <iostream>
# include "Interface.hpp"
# include "Factory.hpp"
# include "Error.hpp"
# include "Snake.hpp"
# include "Food.hpp"
# include "Display.hpp"

class Game {
	public:
		Game( void );
		Game( Game const & src );
		~Game( void );

		Game & operator=( Game const & src );

		void	runNibbler( void );
		Food	food;
		Snake	snake;
		Factory	factory;

	private:
		int		_width;
		int		_height;
};

#endif
