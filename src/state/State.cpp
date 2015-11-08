/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   State.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:16:53 by npineau           #+#    #+#             */
/*   Updated: 2015/11/07 21:14:45 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ncurses.h>
#include "State.hpp"
#include "Unit.hpp"
#include <string>

/*void State::display(Unit const& unit) {
}*/

void State::setMissile(int nb)
{
    _missile = nb;
}

int State::getLife(void)
{
    return (_life);
}

void State::setLife(void)
{
    _life--;
}

void State::setScore(void)
{
    _score += 50;
}

void State::score(int score, int life, int missile)
{
    unsigned long i;
    unsigned long j;

    i = 10;
    j = 0;
    std::string mot = "SCORE : ";
    while (j < mot.size())
    {
        mvaddch(_xmax + 1, i++, mot[j]);
        j++;
    }
    mot = std::to_string(score);
    j = 0;
    while (j < mot.size())
    {
        mvaddch(_xmax + 1, i++, mot[j]);
        j++;
    }
    i += 5;
    j = 0;
    mot = "SHIELD : ";
    while (j < mot.size())
    {
        mvaddch(_xmax + 1, i++, mot[j]);
        j++;
    }
    mot = std::to_string(life);
    j = 0;
    while (j < mot.size())
    {
        mvaddch(_xmax + 1, i++, mot[j]);
        j++;
    }
    j = 0;
    mot = "    MISSILE : ";
    while (j < mot.size())
    {
        mvaddch(_xmax + 1, i++, mot[j]);
        j++;
    }
    mot = std::to_string(missile);
    j = 0;
    while (j < mot.size())
    {
        mvaddch(_xmax + 1, i++, mot[j]);
        j++;
    }
}

void State::input(Unit& player) {
    int ch;
    int buff = getch();
    do {
        ch = buff;
        buff = getch();
    } while (buff != ERR);

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
        {
            player.attack();
        }
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
    this->score(this->_score, this->_life, this->_missile);
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

int State::_life = 20;
int State::_missile = 5;
int State::_score = 0;

