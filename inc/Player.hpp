#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Unit.hpp"

class Player : public Unit {
    public:
        void    setDir(Direction dir);
        Direction   getDir(void);
        void    activateAttack(void);
        Player(void);
        Player(Player const & src);

        virtual ~Player(void);

        Player const &operator=(Player const & rhs);

};

#endif
