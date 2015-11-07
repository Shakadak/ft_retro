/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:35:15 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/07 13:35:21 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit.hpp"

Unit::Unit()
{

}

Unit::Unit(int x, int y, char c) : _x(x), _y(y), _type(c)
{

}

Unit::Unit(Unit const & str)
{
	*this = str;
}

Unit & Unit::operator=(Unit const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_type = rhs.getC();
	return (*this);
}

char Unit::getC(void) const
{
	return (this->_type);
}

int Unit::getX(void) const
{
	return(this->_x);
}

int Unit::getY(void) const
{
	return(this->_y);
}

char** Unit::right(char **tab)
{
	tab[this->_y][this->_x] = ' ';
	this->_x++;
	tab[this->_y][this->_x] = this->_type;
}

char** Unit::left(char **tab)
{
	tab[this->_y][this->_x] = ' ';
	this->_x--;
	tab[this->_y][this->_x] = this->_type;
}

char **Unit::up(char **tab)
{
	tab[this->_y][this->_x] = ' ';
	this->_y--;
	tab[this->_y][this->_x] = this->_type;
}

char **Unit::down(char **tab)
{
	tab[this->_y][this->_x] = ' ';
	this->_y++;
	tab[this->_y][this->_x] = this->_type;
}
