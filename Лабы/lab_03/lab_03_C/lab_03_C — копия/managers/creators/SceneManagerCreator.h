#ifndef SCENE_MANAGER_CREATOR_H
#define SCENE_MANAGER_CREATOR_H

#include <memory>

#include "BaseManagerCreator.h"
#include "SceneManager.h"

class SceneManagerCreator : public BaseManagerCreator
{
public:
    auto createManager() -> std::shared_ptr<SceneManager>;

private:
    void createInstance();

    std::shared_ptr<SceneManager> _manager;
};

#endif // SCENE_MANAGER_CREATOR_H
