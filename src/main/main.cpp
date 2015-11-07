/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:20:41 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/07 19:35:52 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include "unit.hpp"
#include "State.hpp"

void init(void) {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    //nodelay(stdscr, TRUE);
    halfdelay(1);
    curs_set(0);
}

void game_loop(void)
{
    State game(20, 100);
    Unit j(10, 10, '>');
    Unit *e = new Unit[10];
    int i = 0;
    int k;
    int nbA;

    while (i < 10)
    {
        nbA = rand() % 29;
        e[i] = Unit(nbA, 99, '<');
        i++;
    }

    j.left(game.getGrid());
    while (42)
    {
        game.input(j);

        i = 0;
        while (i < 10)
        {
            if (e[i].death() == 1)
            {
                nbA = rand() % 29;
                e[i] = Unit(nbA, 99, '<');
            }
            k = rand() % 50;
            if (k == 2)
            {
                e[i].eAttack();
            }
            e[i].left(game.getGrid());
            i++;
        }
        j.rLife(game.getGrid());
        j.rAttack(game.getGrid());
        i = 0;
        while (i < 10)
        {
            e[i].rEnnemy(game.getGrid());
            i++;
        }
        if (j.death() == 1)
            break;
        game.render();
    }
    delete [] e;
}

int main(void)
{
    srand(time(0));
    init();
    game_loop();
    endwin();
    return 0;
}

