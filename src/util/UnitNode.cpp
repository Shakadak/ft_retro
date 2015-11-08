#include "UnitNode.hpp"

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
