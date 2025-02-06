#ifndef BASE_CAMERA_BUILDER_H
#define BASE_CAMERA_BUILDER_H

#include "Camera.h"
#include "BaseBuilder.h"
#include "BaseCarcassModelReader.h"

class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    explicit BaseCameraBuilder(std::shared_ptr<BaseCarcassModelReader> &reader) : _reader(reader) {}
    virtual ~BaseCameraBuilder() = default;

    virtual void buildLocation() = 0;

    virtual std::shared_ptr<Camera> get() = 0;

protected:
    std::shared_ptr<BaseCarcassModelReader> _reader;
    std::shared_ptr<Camera> _camera;
};

#endif // BASE_CAMERA_BUILDER_H
