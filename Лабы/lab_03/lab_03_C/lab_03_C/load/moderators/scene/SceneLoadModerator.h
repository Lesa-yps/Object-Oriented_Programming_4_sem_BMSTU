#ifndef SCENE_LOAD_MODERATOR_H
#define SCENE_LOAD_MODERATOR_H

#include "BaseSceneBuildDirector.h"
#include "BaseLoadModerator.h"
#include "SceneBuilder.h"
#include "CarcassModelReaderFactory.h"
#include "BaseSceneBuilder.h"
#include "FileCarcassModelReader.h"

class SceneLoadModerator
{
public:
    SceneLoadModerator() = default;
    explicit SceneLoadModerator(std::shared_ptr<BaseSceneBuildDirector> director);

    ~SceneLoadModerator() = default;

    std::shared_ptr<Scene> load(const std::string &fileName);

private:
    std::shared_ptr<BaseSceneBuildDirector> _director;
};

#endif // SCENE_LOAD_MODERATOR_H
