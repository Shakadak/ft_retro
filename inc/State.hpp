#ifndef STATE_HPP
# define STATE_HPP

class State {
    public:
        State(void);
        State(State const& src);
        State(unsigned int x, unsigned int y);
        ~State(void);
        State&  operator=(State const& rhs);

        void    render(void);
        char**  getGrid(void);

    private:
        char**  _grid;
        unsigned int    _xmax;
        unsigned int    _ymax;
};

#endif
