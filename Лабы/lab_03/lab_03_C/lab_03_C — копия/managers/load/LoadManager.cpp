#include <QDebug>

#include "LoadManager.h"

auto LoadManager::load(std::string &name) -> std::shared_ptr<Object>
{
    return _moderator->load(name);
}

auto LoadManager::loadScene(std::string &name) -> std::shared_ptr<Scene>
{
    return _sceneModerator->load(name);
}

void LoadManager::setModerator(std::shared_ptr<BaseLoadModerator> moderator)
{
    _moderator = moderator;
}

void LoadManager::setSceneModerator(std::shared_ptr<SceneLoadModerator> moderator)
{
    _sceneModerator = moderator;
}
