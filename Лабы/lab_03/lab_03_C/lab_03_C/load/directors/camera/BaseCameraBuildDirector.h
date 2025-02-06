#ifndef BASE_CAMERA_BUILD_DIRECTOR_H
#define BASE_CAMERA_BUILD_DIRECTOR_H

#include "BaseDirector.h"
#include "CameraBuilder.h"

class BaseCameraBuildDirector : public BaseDirector
{
public:
    virtual std::shared_ptr<Camera> create(std::shared_ptr<BaseCameraBuilder> builder) = 0;
};

#endif // BASE_CAMERA_BUILD_DIRECTOR_H
