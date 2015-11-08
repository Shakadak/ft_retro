#include "UnitList.hpp"

void    UnitList::iterate(void (*f)(Unit &)) {
    f(*_cell);
    if (_next) {
        _next->iterate(f);
    }
}

UnitList&   UnitList::filter(bool (*p)(Unit const&)) {
    UnitList* next = _next;
    if (!p(*_cell)){
        this->remove();
    }
    /*if (prev) {
        prev->filter(p);
    }*/
    if (next) {
        next->filter(p);
    }
}

UnitList::UnitList(void) : _cell(NULL), _next(NULL), _prev(NULL) {
}

UnitList::UnitList(UnitList const& node) {
    _cell = new Unit(*node._cell);
    _next = new UnitList(*node._next);
}

UnitList::UnitList(UnitList* prev, Unit* cell)
    : _cell(cell), _next(prev->_next), _prev(prev) {
        if (prev->_next){
            prev->_next->_prev = this;
            prev->_next = this;
        }
}

UnitList::UnitList(Unit* cell, UnitList* next)
    : _cell(cell), _next(next), _prev(next->_prev) {
        if (next->_prev) {
            next->_prev->_next = this;
            next->_prev = this;
        }
}

UnitList::UnitList(Unit* cell) : _cell(cell), _next(NULL), _prev(NULL) {
}

UnitList::~UnitList(void) {
    delete _cell;
    _cell = NULL;
    delete _prev;
    _prev = NULL;
    delete _next;
    _next = NULL;
}

UnitList&   UnitList::operator=(UnitList const& node) {
    _cell = node._cell;
    _next = node._next;
    return (*this);
}

void        UnitList::remove(void) {
    if (_next) {
        _next->_prev = _prev;
    }
    if (_prev) {
        _prev->_next = _next;
    }
    _next = NULL;
    _prev = NULL;
    delete this;
}

void        UnitList::add(Unit* cell) {
    if (_cell == NULL) {
        _cell = cell;
    }
    else if (_next == NULL) {
        new UnitList(this, cell);
    }
    else {
        _next->add(cell);
    }
}
