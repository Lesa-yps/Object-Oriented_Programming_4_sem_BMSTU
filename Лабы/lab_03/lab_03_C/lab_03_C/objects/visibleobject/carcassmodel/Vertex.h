#ifndef VERTEX_H
#define VERTEX_H

#include "Matrix.h"
#include "Transformer.h"

class Vertex
{
public:
    Vertex() = default;
    Vertex(const double x, const double y, const double z);

    Vertex(const Vertex &vertex) = default;
    auto operator=(const Vertex &vertex) -> Vertex & = default;

    Vertex(const Vertex &&vertex) noexcept;
    auto operator=(Vertex &&vertex) noexcept -> Vertex &;

    ~Vertex() = default;


    [[nodiscard]] auto getX() const -> double;
    [[nodiscard]] auto getY() const -> double;
    [[nodiscard]] auto getZ() const -> double;

    void setX(double const x);
    void setY(double const y);
    void setZ(double const z);

    auto operator==(const Vertex &vertex) const noexcept -> bool;

    auto operator+(const Vertex &vertex)  const -> Vertex;
    auto operator-(const Vertex &vertex)  const -> Vertex;

    auto getAbsVertex(const Vertex &center) -> Vertex;

    [[nodiscard]] auto getCenter() const -> Vertex;
    void transform(Transformer &mtr);

private:
    double _x;
    double _y;
    double _z;
};

#endif // VERTEX_H
