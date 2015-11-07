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
			tab[i][j] = ' ';
			j++;
		}
		i++;
	}
	tab[20][12] = 'p';
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
	int i;
	int nbA;
	int k;

	i = 0;
	Unit j(10, 10, '>');
	Unit *e = new Unit[10];

	while (i < 10)
	{
		nbA = rand() % 29;
		e[i] = Unit(nbA, 99, '<');
		i++;
	}
	tab = j.left(tab);
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
        i = 0;
        while (i < 10)
        {
        	if (e[i].death() == 1)
        	{
        		nbA = rand() % 29;
				e[i] = Unit(nbA, 99, '<');
        	}
        	k = rand() % 5;
			if (k == 2)
			{
				e[i].eAttack();
			}
	     	e[i].left(tab);
 	      	i++;
        }
        tab = j.rAttack(tab);
        i = 0;
        while (i < 10)
        {
        	tab = e[i].rEnnemy(tab);
        	i++;
        }
        j.rLife(tab);
        if (j.death() == 1)
        	break;
		display(tab, x, y);
		refresh();
    }
    delete [] e;
}

int main(void)
{
	int x;
	int y;

	srand(time(0));
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

