/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:29:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/11 18:06:33 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Food.hpp"
#include "Game.hpp"

Food::Food(void)
{

}

Food::~Food(void)
{

}

int		Food::getXPos(void) const
{
	return _xPos;
}

int		Food::getYPos(void) const
{
	return _yPos;
}

void	Food::spawnFood(void)
{
	int	maxX = (_windowSize.x / _blockSize) - 2;
	int	maxY = (_windowSize.y / _blockSize) - 2;
	 = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	m_appleShape.setPosition(m_item.x * m_blockSize, m_item.y * m_blockSize);
}