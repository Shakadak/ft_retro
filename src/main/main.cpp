/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:20:41 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/08 19:33:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <sys/time.h>
#include "Unit.hpp"
#include "UnitList.hpp"
#include "State.hpp"

static void init(void) {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
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
    Player j;
    Unit *e = new Unit[10];
    int i = 0;
    int nbA;
    long long interval = 50;
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
                game.setScore();
                e[i].rEnnemy(game.getGrid());
                nbA = rand() % 29;
                e[i] = Unit(nbA, 99);
            }
            nbA = rand() % 50;
            if (nbA == 2)
            {
                e[i].eAttack();
            }
            e[i].left(game.getGrid());
            nbA = rand() % 35;
            if (nbA == 2)
                e[i].down(game.getGrid());
            else if (nbA == 1)
                e[i].up(game.getGrid());
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
        {
            j.setDeath();
            game.setLife();
        }
        game.setMissile(j.getMiss());
        if (game.getLife() < 0)
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

