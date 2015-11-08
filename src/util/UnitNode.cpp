#include "UnitNode.hpp"

void    UnitNode::iterate(void (*f)(Unit &)) {
    f(*_cell);
    if (_next) {
        _next->iterate(f);
    }
}

void    UnitNode::filter(bool (*p)(Unit const&)) {
    //UnitNode* prev = _prev;
    UnitNode* next = _next;
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

UnitNode::UnitNode(void) : _cell(NULL), _next(NULL), _prev(NULL) {
}

UnitNode::UnitNode(UnitNode const& node) {
    _cell = new Unit(*node._cell);
    _next = new UnitNode(*node._next);
}

UnitNode::UnitNode(UnitNode* prev, Unit* cell)
    : _cell(cell), _next(prev->_next), _prev(prev) {
        if (prev->_next){
            prev->_next->_prev = this;
            prev->_next = this;
        }
}

UnitNode::UnitNode(Unit* cell, UnitNode* next)
    : _cell(cell), _next(next), _prev(next->_prev) {
        if (next->_prev) {
            next->_prev->_next = this;
            next->_prev = this;
        }
}

UnitNode::UnitNode(Unit* cell) : _cell(cell), _next(NULL), _prev(NULL) {
}

UnitNode::~UnitNode(void) {
    delete _cell;
    _cell = NULL;
    delete _prev;
    _prev = NULL;
    delete _next;
    _next = NULL;
}

UnitNode&   UnitNode::operator=(UnitNode const& node) {
    _cell = node._cell;
    _next = node._next;
    return (*this);
}

void        UnitNode::remove(void) {
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

void        UnitNode::add(Unit* cell) {
    if (_cell == NULL) {
        _cell = cell;
    }
    else if (_next == NULL) {
        new UnitNode(this, cell);
    }
    else {
        _next->add(cell);
    }
}
