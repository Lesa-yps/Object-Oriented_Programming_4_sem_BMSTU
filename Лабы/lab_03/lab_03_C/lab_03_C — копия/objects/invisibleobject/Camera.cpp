#include "Camera.h"

Camera::Camera(Vertex location) : _location(std::move(location)) { }

void Camera::transform(Transformer &mtr, const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;
    _location = _location + diff;
    Matrix<double> cur_location = {{_location.getX(), _location.getY(), _location.getZ(), 1.}};
    Matrix<double> new_location = cur_location * mtr.GetMatrix();
    _location = Vertex(new_location[0][0], new_location[0][1], new_location[0][2]);
    _location = _location - diff;
}

auto Camera::getCenter() const -> Vertex
{
    return _location;
}
