#ifndef SCENE_LOAD_MODERATOR_CREATOR_H
#define SCENE_LOAD_MODERATOR_CREATOR_H

#include "SceneLoadModerator.h"

class SceneLoadModeratorCreator
{
public:
    std::shared_ptr<SceneLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<SceneLoadModerator> _moderator;
};

#endif // SCENE_LOAD_MODERATOR_CREATOR_H
