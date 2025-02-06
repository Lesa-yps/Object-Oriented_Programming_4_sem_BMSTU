#ifndef CAMERA_LOAD_MODERATOR_CREATOR_H
#define CAMERA_LOAD_MODERATOR_CREATOR_H

#include "BaseCameraBuildDirector.h"
#include "CameraLoadModerator.h"

class CameraLoadModeratorCreator
{
public:
    std::shared_ptr<CameraLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<CameraLoadModerator> _moderator;
};

#endif // CAMERA_LOAD_MODERATOR_CREATOR_H
