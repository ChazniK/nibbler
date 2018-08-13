/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:58:03 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/13 11:50:36 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Food.hpp"

Food::Food(void)
{
	spawnFood();
}

Food::Food(const Food & src)
{
	*this = src;
	return;
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

void	Food::spawnFood()
{
	//width and height passed in from game class
	int	maxX = (width / blockSize) - 2;
	int	maxY = (height/ blockSize) - 2;

	_xPos = (rand() % maxX + 1);
	_yPos = (rand() % maxY + 1);
}

Food 	&Food::operator=( const Food & rhs )
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}