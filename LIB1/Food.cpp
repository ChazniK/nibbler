/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:29:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/12 01:20:49 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Food.hpp"
#include "Game.hpp"

Food::Food(void)
{
	std::cout << "Constructor to spawn food\n";
	spawnFood();
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
	int	maxX = (WIDTH / blockSize) - 2;
	int	maxY = (HEIGHT / blockSize) - 2;

	_xPos = std::rand() % maxX + 1;
	_yPos = std::rand() % maxY + 1;
}
