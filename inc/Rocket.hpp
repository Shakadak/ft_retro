#ifndef ROCKET_HPP
# define ROCKET_HPP

#include "Unit.hpp"

class Rocket : public Unit {
    public:
        Rocket(int x, int y, Unit::Direction dir);
        Rocket(void);
        Rocket(Rocket const & src);

        virtual ~Rocket(void);

        Rocket const &operator=(Rocket const & rhs);
};

#endif
