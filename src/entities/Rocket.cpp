
#include "Rocket.hpp"


Rocket(int x, int y, Unit::Direction dir) {
    _x = x;
    _y = y;
    _dir = dir;
    _type = '-';
    _speed = 2;
}
}

Rocket::Rocket(void) {
}

Rocket::Rocket(Rocket const & src) {
    *this = src;
}


Rocket::~Rocket(void) {
}


Rocket const &Rocket::operator=(Rocket const & rhs) {
    *this = rhs;
    return (*this);
}
