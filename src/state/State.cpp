/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   State.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:16:53 by npineau           #+#    #+#             */
/*   Updated: 2015/11/07 17:53:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ncurses.h>
#include "State.hpp"
#include "Unit.hpp"

/*void State::display(Unit const& unit) {
}*/

void State::input(Unit& player) {
    int ch = getch();
    switch(ch) {
        case 'q':
        case 'Q':
            endwin();
            std::exit(EXIT_SUCCESS);
            break;
        case KEY_LEFT:
            player.left(_grid);
            break;
        case KEY_RIGHT:
            player.left(_grid);
            break;
        case KEY_UP:
            player.left(_grid);
            break;
        case KEY_DOWN:
            player.left(_grid);
            break;
        case ' ':
            player.attack();
    }
    player.rAttack(_grid);
}

void State::render(void) {
    for( unsigned int i = 0; i < _ymax; i++) {
        for (unsigned int j = 0; j < _xmax; j++) {
            mvaddch(j, i, _grid[i][j]);
        }
    }
    refresh();
}

char**  State::getGrid(void) {
    return (this->_grid);
}


char**  State::clearGrid(void) {
    for( unsigned int i = 0; i < _ymax; i++) {
        for (unsigned int j = 0; j < _xmax; j++) {
            _grid[i][j] = 'x';
        }
    }
    return _grid;
}

State::State(void) : _xmax(0), _ymax(0) {
}

State::State(State const& src)  : _xmax(src._xmax), _ymax(src._ymax) {
    char **tab = new char*[_xmax];
    for (unsigned int i=0; i < _xmax; i++)
        tab[i] = new char[_ymax];

    for( unsigned int i = 0; i < _ymax; i++) {
        for (unsigned int j = 0; j < _xmax; j++) {
            _grid[i][j] = src._grid[i][j];
        }
    }
}

State::State(unsigned int x, unsigned int y) : _xmax(x), _ymax(y) {
    char **tab = new char*[_xmax];
    for (unsigned int i=0; i < _xmax; i++)
        tab[i] = new char[_ymax];

    clearGrid();
}

State::~State(void) {
    for(unsigned int i = 0; i < _xmax; i++) {
        delete [] _grid[i];
    }
    delete [] _grid;
}

State&  State::operator=(State const& rhs) {
    _xmax = rhs._xmax;
    _ymax = rhs._ymax;
    _grid = rhs._grid;
    return (*this);
}
