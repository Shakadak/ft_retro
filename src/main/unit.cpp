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
	this->_att = new int*[this->_attmax];
	for (int i = 0; i < this->_attmax; i++)
		this->_att[i] = new int[3];
	for (int i=0; i < this->_attmax; i++)
    	for (int j=0; j < 3; j++)
      		this->_att[i][j] = 0;
    this->_death = 0;
}

Unit::Unit(int x, int y, char c) : _x(x), _y(y), _type(c)
{
	this->_att = new int*[this->_attmax];
	for (int i = 0; i < this->_attmax; i++)
		this->_att[i] = new int[3];
	for (int i=0; i < this->_attmax; i++)
    	for (int j=0; j < 3; j++)
      		this->_att[i][j] = 0;
    this->_death = 0;
}

Unit::Unit(Unit const & str)
{
	*this = str;
}

Unit::~Unit()
{
	// for (int i=0; i < this->_attmax; i++)
 //    	delete[] this->_att[i];
 //  	delete[] this->_att;
}

Unit & Unit::operator=(Unit const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_type = rhs.getC();
	this->_death = rhs.death();
	this->_att = rhs.getAtt();
	return (*this);
}

int** Unit::getAtt(void) const 
{
	return(this->_att);
}

int Unit::death(void) const
{
	return (this->_death);
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
	if (this->_y < this->_ymax - 1)
	{
		tab[this->_y][this->_x] = ' ';
		this->_y++;
		if (tab[this->_y][this->_x] == ' ')
			tab[this->_y][this->_x] = this->_type;
		else
			this->_death = 1;
	}
	return tab;
}

char** Unit::left(char **tab)
{
	if (this->_y > this->_ymin)
	{
		tab[this->_y][this->_x] = ' ';
		this->_y--;
		if (tab[this->_y][this->_x] == ' ')
			tab[this->_y][this->_x] = this->_type;
		else
			this->_death = 1;
	}
	return tab;
}

char **Unit::up(char **tab)
{
	if (this->_x > this->_xmin)
	{
		tab[this->_y][this->_x] = ' ';
		this->_x--;
		if (tab[this->_y][this->_x] == ' ')
			tab[this->_y][this->_x] = this->_type;
		else
			this->_death = 1;
	}
	return tab;
}

char **Unit::down(char **tab)
{
	if (this->_x < this->_xmax - 1)
	{
		tab[this->_y][this->_x] = ' ';
		this->_x++;
		if (tab[this->_y][this->_x] == ' ')
			tab[this->_y][this->_x] = this->_type;
		else
			this->_death = 1;
	}
	return tab;
}

void Unit::attack(void)
{
	int i = 0;
	while (this->_att[i][0] != 0 && i < this->_attmax - 1)
		i++;
	if (i < this->_attmax - 1)
	{
		this->_att[i][0] = 1;
		this->_att[i][1] = this->_x;
		this->_att[i][2] = this->_y + 1;
	}
}

void Unit::eAttack(void)
{
	int i = 0;
	while (this->_att[i][0] != 0 && i < this->_attmax - 1)
		i++;
	if (i < this->_attmax - 1)
	{
		this->_att[i][0] = 1;
		this->_att[i][1] = this->_x;
		this->_att[i][2] = this->_y - 1;
	}
}

char** Unit::rAttack(char **tab)
{
	int i = 0;
	while (i < this->_attmax)
	{
		if (this->_att[i][0] == 1)
		{
			tab[this->_att[i][2]][this->_att[i][1]] = ' ';
			this->_att[i][2]++;
			if (this->_att[i][2] < this->_ymax)
				tab[this->_att[i][2]][this->_att[i][1]] = '-';
			else
				this->_att[i][0] = 0;
		}
		i++;
	}
	return tab;
}

char** Unit::rEnnemy(char **tab)
{
	int i = 0;
	if (this->_y <= 1)
	{
		tab[this->_y][this->_x] = ' ';
		this->_death = 1;
	}
	while (i < this->_attmax)
	{
		if (this->_att[i][0] == 1)
		{
			tab[this->_att[i][2]][this->_att[i][1]] = ' ';
			this->_att[i][2]-=2;
			if (this->_att[i][2] > this->_ymin)
				tab[this->_att[i][2]][this->_att[i][1]] = '-';
			else
				this->_att[i][0] = 0;
		}
		i++;
	}
	return tab;
}

void Unit::rLife(char **tab)
{
	int i;
	int j;

	i = 0;
	while(i != this->_ymax)
	{
		j = 0;
		while(j != this->_xmax)
		{
			if (tab[i][j] == '>')
				return;
			j++;
		}
		i++;
	}
	this->_death = 1;
}

int Unit::_xmax = 20;
int Unit::_xmin = 0;
int Unit::_ymax = 100;
int Unit::_ymin = 0;
int Unit::_attmax = 5;
