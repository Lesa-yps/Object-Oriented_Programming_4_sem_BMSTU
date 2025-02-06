#include "Edge.h"

Edge::Edge(const std::size_t firstVertex, const std::size_t secondVertex)
{
    setFirst(firstVertex);
    setSecond(secondVertex);
}

auto Edge::getFirst() const -> std::size_t
{
    return _first;
}

auto Edge::getSecond() const -> std::size_t
{
    return _second;
}

void Edge::setFirst(const std::size_t index)
{
    _first = index;
}

void Edge::setSecond(const std::size_t index)
{
    _second = index;
}
