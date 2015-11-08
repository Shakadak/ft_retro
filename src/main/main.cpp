/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:20:41 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/08 13:02:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <sys/time.h>
#include "Unit.hpp"
#include "UnitNode.hpp"
#include "State.hpp"

static void init(void) {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    //halfdelay(1);
    curs_set(0);
}

static long long getTime() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static void game_loop(void)
{
    State game(20, 100);
    Unit j(10, 10, '>');
    Unit *e = new Unit[10];
    int i = 0;
    int k;
    int nbA;
    long long interval = 100;
    long long t0, t1;

    t0 = getTime();
    while (i < 10)
    {
        nbA = rand() % 29;
        e[i] = Unit(nbA, 99);
        i++;
    }

    j.left(game.getGrid());
    while (42)
    {
        t1 = getTime();
        if ( t1 < t0 + interval) {
            continue;
        }
        else {
            t0 = t1;
        }
        game.input(j);

        i = 0;
        while (i < 10)
        {
            if (e[i].death() == 1)
            {
                e[i].rEnnemy(game.getGrid());
                nbA = rand() % 29;
                e[i] = Unit(nbA, 99);
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

