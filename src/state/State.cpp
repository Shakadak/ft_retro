/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   State.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:16:53 by npineau           #+#    #+#             */
/*   Updated: 2015/11/07 18:27:33 by npineau          ###   ########.fr       */
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
            player.right(_grid);
            break;
        case KEY_UP:
            player.up(_grid);
            break;
        case KEY_DOWN:
            player.down(_grid);
            break;
        case ' ':
            player.attack();
    }
    player.rAttack(_grid);
    player.rLife(_grid);
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
            _grid[i][j] = ' ';
        }
    }
    return _grid;
}

State::State(void) : _xmax(0), _ymax(0) {
}

State::State(State const& src)  : _xmax(src._xmax), _ymax(src._ymax) {
    char **tab = new char*[_ymax];
    for (unsigned int i=0; i < _ymax; i++)
        tab[i] = new char[_xmax];

    for( unsigned int i = 0; i < _ymax; i++) {
        for (unsigned int j = 0; j < _xmax; j++) {
            _grid[i][j] = src._grid[i][j];
        }
    }
}

State::State(unsigned int x, unsigned int y) : _xmax(x), _ymax(y) {
    _grid = new char*[_ymax];
    for (unsigned int i=0; i < _ymax; i++)
        _grid[i] = new char[_xmax];

    clearGrid();
}

State::~State(void) {
    for(unsigned int i = 0; i < _ymax; i++) {
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
