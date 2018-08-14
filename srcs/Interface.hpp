/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:40:11 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/14 15:53:43 by mafernan         ###   ########.fr       */
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
	F3
};

class Interface
{
	public:
		virtual void Init(int width, int height) = 0;
		virtual Keys getKey( void ) = 0;
		virtual void Render(int foodX, int foodY, std::vector<Block> snake) = 0;
		virtual bool PollEvents( void ) = 0;
		virtual void CloseWindow( void ) = 0;
		virtual void BackGround( void ) = 0;
};

#endif

