#include "Player.hpp"

void    Player::setDir(Direction dir) {
    _dir = dir;
}

Unit::Direction   Player::getDir(void) {
    Direction   dir = _dir;
    _dir = None;
    return (dir);
}

void    Player::activateAttack(void) {
    _atk = true;
}

Player::Player(void) {
    _x = 10;
    _y = 10;
    _type = '>';
}

Player::Player(Player const & src) {
    *this = src;
}


Player::~Player(void) {
}


Player const &Player::operator=(Player const & rhs) {
    *this = rhs;
    return (*this);
}
