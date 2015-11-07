/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:20:41 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/07 18:49:35 by npineau          ###   ########.fr       */
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

    j.left(game.getGrid());
    while (42)
    {
        game.input(j);
        if (j.death() == 1)
            break;
        game.render();
    }
}

int main(void)
{
    init();
    game_loop();
    endwin();
    return 0;
}

