#ifndef CAMERA_LOAD_MODERATOR_H
#define CAMERA_LOAD_MODERATOR_H

#include "BaseLoadModerator.h"
#include "BaseCameraBuildDirector.h"
#include "CarcassModelReaderFactory.h"
#include "BaseCameraBuilder.h"
#include "BaseCarcassModelReader.h"

class CameraLoadModerator : public BaseLoadModerator
{
public:
    explicit CameraLoadModerator(std::shared_ptr<BaseCameraBuildDirector> director);
    ~CameraLoadModerator() = default;

    std::shared_ptr<Object> load(const std::string &fileName) override;

private:
    std::shared_ptr<BaseCameraBuildDirector> _director;
};

#endif // CAMERA_LOAD_MODERATOR_H
