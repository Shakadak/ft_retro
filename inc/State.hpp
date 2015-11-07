#ifndef STATE_HPP
# define STATE_HPP

#include "Unit.hpp"

class State {
    public:
        State(void);
        State(State const& src);
        State(unsigned int x, unsigned int y);
        ~State(void);
        State&  operator=(State const& rhs);

        void    input(Unit& player);
        void    render(void);
        char**  getGrid(void);
        char**  clearGrid(void);

    private:
        char**  _grid;
        unsigned int    _xmax;
        unsigned int    _ymax;
};

#endif
