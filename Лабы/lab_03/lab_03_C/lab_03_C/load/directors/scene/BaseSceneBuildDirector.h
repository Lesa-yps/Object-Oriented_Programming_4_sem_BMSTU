#ifndef BASE_SCENE_BUILD_DIRECTOR_H
#define BASE_SCENE_BUILD_DIRECTOR_H

#include "SceneBuilder.h"

class BaseSceneBuildDirector
{
public:
    virtual std::shared_ptr<Scene> create(std::shared_ptr<SceneBuilder> builder) = 0;
};

#endif // BASE_SCENE_BUILD_DIRECTOR_H
