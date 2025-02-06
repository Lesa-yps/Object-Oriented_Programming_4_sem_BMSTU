#include "Composite.h"

Composite::Composite(std::shared_ptr<Object> &element)
{
    _elements.push_back(element);
    updateCenter();
}

Composite::Composite(const std::vector<std::shared_ptr<Object>> &elements)
    : _elements(elements)
{
    updateCenter();
}

auto Composite::add(const std::shared_ptr<Object> &element) -> bool
{
    _elements.push_back(element);
    updateCenter();

    return true;
}

auto Composite::remove(const Iterator &iter) -> bool
{
    _elements.erase(iter);
    updateCenter();

    return true;
}

void Composite::updateCenter()
{
    _center = Vertex(0, 0, 0);
    size_t count = 0;
    for (const auto &element : _elements)
    {
        _center = _center + element->getCenter();
        count++;
    }
    _center = Vertex(_center.getX() / count, _center.getY() / count, _center.getZ() / count);
}

auto Composite::isVisible() -> bool
{
    return false;
}

auto Composite::isComposite() -> bool
{
    return true;
}

auto Composite::getCenter() const -> Vertex
{
    return _center;
}

void Composite::moveElemsToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;
    TransformerMove mtr(diff.getX(), diff.getY(), diff.getZ());
    //Transformer mtr = Transformer(diff.getX(), diff.getY(), diff.getZ(), 1, 1, 1, 0, 0, 0);
    transformElems(mtr);
    updateCenter();
}

void Composite::transformElems(Transformer &mtr)
{
    for (const auto &element : _elements)
    {
        element->updateCenter();
        element->transform(mtr, _center);
    }
}

void Composite::moveElemsToCenter(const Vertex &center)
{
    Vertex diff = center - _center;
    TransformerMove mtr(diff.getX(), diff.getY(), diff.getZ());
    //Transformer mtr = Transformer(diff.getX(), diff.getY(), diff.getZ(), 1, 1, 1, 0, 0, 0);
    transformElems(mtr);
    updateCenter();
}

void Composite::transform(Transformer &mtr, const Vertex &center)
{
    updateCenter();
    moveElemsToOrigin(center);
    transformElems(mtr);
    moveElemsToCenter(center);
}

auto Composite::begin() -> Iterator
{
    return _elements.begin();
}

auto Composite::end() -> Iterator
{
    return _elements.end();
}
