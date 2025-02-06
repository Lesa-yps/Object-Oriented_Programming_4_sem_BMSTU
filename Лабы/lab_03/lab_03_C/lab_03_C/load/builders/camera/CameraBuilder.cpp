#include "CameraBuilder.h"

CameraBuilder::CameraBuilder(std::shared_ptr<BaseCarcassModelReader> reader) : BaseCameraBuilder(reader) {}

void CameraBuilder::buildLocation()
{
    auto location = _reader->readVertex();
    _camera = std::make_shared<Camera>(Camera(location));
}

std::shared_ptr<Camera> CameraBuilder::get()
{
    return _camera;
}
