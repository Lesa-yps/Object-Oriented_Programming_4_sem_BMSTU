#include <cmath>
#include "Vertex.h"

#define TO_RAD_COEF (M_PI / 180)

auto toRadians(const double angle) -> double
{
    return angle * TO_RAD_COEF;
}

Vertex::Vertex(const double x, const double y, const double z)
{
    setX(x);
    setY(y);
    setZ(z);
}

Vertex::Vertex(const Vertex &&vertex) noexcept
{
    setX(vertex._x);
    setY(vertex._y);
    setZ(vertex._z);
    vertex.~Vertex();
}

auto Vertex::operator=(Vertex &&vertex) noexcept -> Vertex &
{
    setX(vertex._x);
    setY(vertex._y);
    setZ(vertex._z);
    vertex.~Vertex();
    return *this;
}

auto Vertex::getX() const -> double
{
    return _x;
}

auto Vertex::getY() const -> double
{
    return _y;
}

auto Vertex::getZ() const -> double
{
    return _z;
}

void Vertex::setX(const double x)
{
    _x = x;
}

void Vertex::setY(const double y)
{
    _y = y;
}

void Vertex::setZ(const double z)
{
    _z = z;
}

auto Vertex::operator==(const Vertex &vertex) const noexcept -> bool
{
    return (vertex._x == _x) && (vertex._y == _y) && (vertex._z == _z);
}

auto Vertex::operator+(const Vertex &vertex) const -> Vertex
{
    Vertex d{*this};
    d.setX(d._x + vertex._x);
    d.setY(d._y + vertex._y);
    d.setZ(d._z + vertex._z);
    return d;
}

auto Vertex::operator-(const Vertex &vertex) const -> Vertex
{
    Vertex d{*this};
    d.setX(d._x - vertex._x);
    d.setY(d._y - vertex._y);
    d.setZ(d._z - vertex._z);
    return d;
}

void Vertex::transform(Transformer &mtr)
{
    Matrix<double> cur_location = {{_x, _y, _z, 1.}};
    Matrix<double> new_location = cur_location * mtr.GetMatrix();
    _x = new_location[0][0];
    _y = new_location[0][1];
    _z = new_location[0][2];
}

auto Vertex::getCenter() const -> Vertex
{
    return *this;
}

auto Vertex::getAbsVertex(const Vertex &center) -> Vertex
{
    return (*this) + center;
}
