#ifndef CAMERA_H
#define CAMERA_H

#include "InvisibleObject.h"

class Camera : public InvisibleObject
{
    friend class DrawCarcassModelAdapter;

public:
    Camera() = default;
    Camera(Vertex location);
    ~Camera() override = default;

    [[nodiscard]] auto getCenter() const -> Vertex override;
    void transform(Transformer &mtr, const Vertex &center) override;
private:
    Vertex _location{};
};

#endif //CAMERA_H
