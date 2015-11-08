#ifndef STATE_HPP
# define STATE_HPP

#include "Unit.hpp"
#include <iostream>

class State {
    public:
        State(void);
        State(State const& src);
        State(unsigned int x, unsigned int y);
        ~State(void);
        State&  operator=(State const& rhs);

        void    score(int score, int life, int missile);
        void    input(Unit& player);
        void    render(void);
        char**  getGrid(void);
        char**  clearGrid(void);
        void    setScore(void);
        void    setLife(void);
        int     getLife(void);
        void    setMissile(int nb);

    private:
        char**  _grid;
        static int _score;
        static int _life;
        static int _missile;
        unsigned int    _xmax;
        unsigned int    _ymax;
};

#endif
