#ifndef FILE_SCENE_BUILD_DIRECTOR_H
#define FILE_SCENE_BUILD_DIRECTOR_H

#include "BaseSceneBuildDirector.h"
#include "FileCarcassModelReader.h"

class FileSceneBuildDirector : public BaseSceneBuildDirector
{
public:
    FileSceneBuildDirector() {}
    ~FileSceneBuildDirector() = default;

    std::shared_ptr<Scene> create(std::shared_ptr<SceneBuilder> builder) override;
};

#endif // FILE_SCENE_BUILD_DIRECTOR_H
