/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:40:11 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/19 11:29:42 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

# include <vector>
# include "debug.hpp" 

enum Keys {
	UPA,
	DOWNA,
	LEFTA,
	RIGHTA,
	ESC,
	F1,
	F2,
	F3,
	UNKNOWN,
	KEYW,
	KEYS,
	KEYA,
	KEYD
};

class Interface
{
	public:
		virtual ~Interface() {}
		virtual void Init(int width, int height) = 0;
		virtual Keys getKey( void ) = 0;
		virtual Keys getKey2( void ) = 0;
		virtual void Render(int foodX, int foodY, int type, std::vector<Block> snake, std::vector<Block> snake2, int set) = 0;
		virtual bool PollEvents( void ) = 0;
};

#endif

