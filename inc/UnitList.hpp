#ifndef UNITLIST_HPP
# define UNITLIST_HPP

# include <cstddef>
# include "Unit.hpp"

class UnitList {
    public:
        bool    any(bool (*p)(Unit const&));
        void    iterate(void (*f)(Unit &));
        UnitList*   filter(bool (*p)(Unit const&));

        UnitList(void);
        UnitList(UnitList const& node);
        UnitList(Unit* cell, UnitList* node);
        UnitList(Unit* cell);
        ~UnitList(void);
        UnitList&   operator=(UnitList const& node);

        void        add(Unit* cell);
        UnitList*   remove(void);

    private:
        Unit*       _cell;
        UnitList*   _next;
};

#endif
