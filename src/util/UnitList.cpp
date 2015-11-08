#include "UnitList.hpp"

bool    UnitList::any(bool (*p)(Unit const&)) {
    if (p(*_cell)) {
        return (true);
    }
    else if (_next) {
        return (_next->any(p));
    }
    else {
        return (true);
    }
}

void    UnitList::iterate(void (*f)(Unit &)) {
    f(*_cell);
    if (_next) {
        _next->iterate(f);
    }
}

UnitList*   UnitList::filter(bool (*p)(Unit const&)) {
    if (p(*_cell)) {
        if (_next) {
            return (new UnitList(new Unit(*_cell), _next->filter(p)));
        }
        return (new UnitList(new Unit(*_cell)));
    }
    else if (this->remove()) {
            return (_next->filter(p));
    }
    else {
        return (NULL);
    }
}

UnitList::UnitList(void) : _cell(NULL), _next(NULL) {
}

UnitList::UnitList(UnitList const& node) {
    _cell = new Unit(*node._cell);
    _next = new UnitList(*node._next);
}

UnitList::UnitList(Unit* cell, UnitList* next)
    : _cell(cell), _next(next) {
}

UnitList::UnitList(Unit* cell) : _cell(cell), _next(NULL) {
}

UnitList::~UnitList(void) {
    delete _cell;
    _cell = NULL;
    delete _next;
    _next = NULL;
}

UnitList&   UnitList::operator=(UnitList const& node) {
    _cell = node._cell;
    _next = node._next;
    return (*this);
}

UnitList*        UnitList::remove(void) {
    UnitList*   next = _next;
    delete this;
    return (next);
}

void        UnitList::add(Unit* cell) {
    if (_cell == NULL) {
        _cell = cell;
    }
    else if (_next == NULL) {
        _next = new UnitList(cell);
    }
    else {
        _next->add(cell);
    }
}
