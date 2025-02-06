#include "CameraLoadModerator.h"

#include "Exceptions.h"
#include "CameraBuilder.h"

CameraLoadModerator::CameraLoadModerator(std::shared_ptr<BaseCameraBuildDirector> director)
    : _director(std::move(director)) { }

std::shared_ptr<Object> CameraLoadModerator::load(const std::string &fileName)
{
    CarcassModelReaderFactory CMreaderFactory;
    auto reader = CMreaderFactory.createReader(fileName);
    auto builder = std::make_shared<CameraBuilder>(reader);
    return _director->create(builder);
}
