#ifndef FILE_CAMERA_BUILD_DIRECTOR_H
#define FILE_CAMERA_BUILD_DIRECTOR_H

#include "BaseCameraBuildDirector.h"
#include "FileCarcassModelReader.h"

class FileCameraBuildDirector : public BaseCameraBuildDirector
{
public:
    FileCameraBuildDirector() {}
    ~FileCameraBuildDirector() override = default;

    std::shared_ptr<Camera> create(std::shared_ptr<BaseCameraBuilder> builder)  override;
};

#endif // FILE_CAMERA_BUILD_DIRECTOR_H
