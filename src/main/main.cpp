/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:20:41 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/07 15:11:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include "unit.hpp"

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

char **init_tab(char **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i != y)
	{
		j = 0;
		while(j != x)
		{
			tab[i][j] = 'x';
			j++;
		}
		i++;
	}
	return tab;
}

void display(char **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i != y)
	{
		j = 0;
		while(j != x)
		{
			mvaddch(j, i, tab[i][j]);
			j++;
		}
		i++;
	}
}

void game_loop(char **tab, int x, int y)
{
	int ch;
	Unit j(10, 10, '>');

	while (42)
	{
		ch = getch();
		if (ch == KEY_LEFT)
		{
			tab = j.left(tab);
		}
		else if (ch == KEY_RIGHT)
		{
			tab = j.right(tab);
		}
		else if (ch == KEY_UP)
		{
			tab = j.up(tab);
		}
		else if (ch == KEY_DOWN)
		{
			tab = j.down(tab);
		}
		else if (ch == 32)
		{
			j.attack();
		}
		else if(ch == 'q' || ch == 'Q') {
            break;
        }
        tab = j.rAttack(tab);
		display(tab, x, y);
		refresh();
    }
}

int main(void)
{
	int x;
	int y;

	x = 20;
	y = 100;
	char **tab = new char*[y];
	for (int i=0; i < y; i++)
		tab[i] = new char[x];
	init();
	init_tab(tab, x, y);
	game_loop(tab, x, y);
	endwin();
	for (int i=0; i < y; i++)
    	delete[] tab[i];
  	delete[] tab;
	return 0;
}

