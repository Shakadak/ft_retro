/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   State.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:16:53 by npineau           #+#    #+#             */
/*   Updated: 2015/11/07 15:55:28 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "State.hpp"

/*void State::display(Unit const& unit) {
}*/

void State::render(void) {
    unsigned int i;
    unsigned int j;

    i = 0;
    while(i != _ymax)
    {
        j = 0;
        while(j != _xmax)
        {
            mvaddch(j, i, _grid[i][j]);
            j++;
        }
        i++;
    }
    refresh();
}


State::State(void) : _xmax(0), _ymax(0) {
}

State::State(State const&) {
}

State::State(unsigned int x, unsigned int y) : _xmax(x), _ymax(y) {
    char **tab = new char*[x];
    for (unsigned int i=0; i < x; i++)
        tab[i] = new char[y];
}

State::~State(void) {}

State&  State::operator=(State const& rhs) {
    _xmax = rhs._xmax;
    _ymax = rhs._ymax;
    _grid = rhs._grid;
    return (*this);
}
