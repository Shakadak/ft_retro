#ifndef UNITLIST_HPP
# define UNITLIST_HPP

# include <cstddef>
# include "Unit.hpp"

class UnitNode {
    public:
        void    iterate(void (*f)(Unit &));
        void    filter(bool (*p)(Unit const&));

        UnitNode(void);
        UnitNode(UnitNode const& node);
        UnitNode(Unit* cell, UnitNode* node);
        UnitNode(UnitNode* node, Unit* cell);
        UnitNode(Unit* cell);
        ~UnitNode(void);
        UnitNode&   operator=(UnitNode const& node);

        void        add(Unit* cell);
        void        remove(void);

    private:
        Unit*       _cell;
        UnitNode*   _next;
        UnitNode*   _prev;
};

#endif
