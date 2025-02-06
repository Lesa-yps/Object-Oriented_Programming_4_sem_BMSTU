#ifndef CAMERA_BUILDER_H
#define CAMERA_BUILDER_H

#include "BaseCameraBuilder.h"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    explicit CameraBuilder(std::shared_ptr<BaseCarcassModelReader> reader);
    ~CameraBuilder() = default;

    void buildLocation() override;

    std::shared_ptr<Camera> get() override;
};

#endif // CAMERA_BUILDER_H
