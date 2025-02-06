#include "FileCameraBuildDirector.h"

std::shared_ptr<Camera> FileCameraBuildDirector::create(std::shared_ptr<BaseCameraBuilder> builder)
{
    builder->buildLocation();
    return builder->get();
}
