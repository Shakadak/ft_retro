/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:35:27 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/08 19:48:49 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_HPP
#define UNIT_HPP

class Unit
{
    public:
        enum Direction {
            Left = -2,
            Down,
            None,
            Up,
            Right
        };
        Unit();
        Unit(int x, int y, char c);
        Unit(int x, int y);
        Unit( Unit const & str);
        virtual ~Unit();

        Unit & operator=(Unit const & rhs);
        char** right(char **tab);
        char** left(char **tab);
        char** up(char **tab);
        char** down(char **tab);
        void attack(void);
        void eAttack(void);
        void rLife(char **tab);
        char** rAttack(char **tab);
        char** rEnnemy(char **tab);

        Direction   getDir(void);
        virtual bool    getAtk(void);
        void    setDeath(void);
        int     **getAtt(void)const;
        int     getMiss(void);
        int     death(void)const;
        int     getX(void)const;
        int     getY(void)const;
        char    getC(void)const;
    protected:
        Direction _dir;
        int _x;
        int _y;
        bool    _atk;
        int **_att;
        int _death;
        static int _attmax;
        static int _xmin;
        static int _ymin;
        static int _xmax;
        static int _ymax;
        char _type;
};

#endif
