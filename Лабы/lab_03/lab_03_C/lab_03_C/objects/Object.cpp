#include "Object.h"

std::size_t Object::_nextId = 1;

Object::Object()
    : _id(_nextId++)
{
};

auto Object::add(const std::shared_ptr<Object> &) -> bool
{
    return false;
};

auto Object::remove(const Iterator &) -> bool
{
    return false;
};

void Object::updateCenter() {

};

auto Object::isVisible() -> bool
{
    return false;
};

auto Object::isComposite() -> bool
{
    return false;
};

auto Object::begin() -> Iterator
{
    return {};
};

auto Object::end() -> Iterator
{
    return {};
};

auto Object::getId() -> std::size_t
{
    return _id;
}
