/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:09:26 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/11 18:27:49 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#define WIDTH = 600
#define HEIGHT = 400
#define blockSize = 20

struct Block
{
	int		x;
	int		y;
	// int		blockSize;

	Block(int xPos, int yPos) : x(xPos), y(yPos) {}
	Block(void);
};

#endif