#ifndef UNITLIST_HPP
# define UNITLIST_HPP

# include <cstddef>
# include "Unit.hpp"

class UnitList {
    public:
        void    iterate(void (*f)(Unit &));
        void    filter(bool (*p)(Unit const&));

        UnitList(void);
        UnitList(UnitList const& node);
        UnitList(UnitList* node, Unit* cell);
        UnitList(Unit* cell);
        ~UnitList(void);
        UnitList&   operator=(UnitList const& node);

        void        add(Unit* cell);
        void        remove(void);

    private:
        Unit*       _cell;
        UnitList*   _next;
};

#endif
