/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:20:41 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/07 13:20:44 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "unit.hpp"

void init(void) {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
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
			tab[i][j] = ' ';
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
			display(tab, x, y);
			refresh();
		}
		else if (ch == KEY_RIGHT)
		{
			tab = j.right(tab);
			display(tab, x, y);
			refresh();
		}
		else if (ch == KEY_UP)
		{
			tab = j.up(tab);
			display(tab, x, y);
			refresh();
		}
		else if (ch == KEY_DOWN)
		{
			tab = j.down(tab);
			display(tab, x, y);
			refresh();
		}
		else if(ch == 'q' || ch == 'Q') {
            break;
        }
    }
}

int main(void)
{
	int x;
	int y;

	x = 100;
	y = 100;
	char **tab = new char*[x];
	for (int i=0; i < x; i++)
		tab[i] = new char[y];
	init();
	init_tab(tab, x, y);
	game_loop(tab, x, y);
	endwin();
	delete tab;
	return 0;
}

