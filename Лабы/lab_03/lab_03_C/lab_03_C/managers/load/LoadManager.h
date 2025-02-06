#ifndef LOAD_MANAGER_H
#define LOAD_MANAGER_H

#include <memory>

#include "BaseManager.h"
#include "BaseLoadModerator.h"
#include "SceneLoadModerator.h"

class LoadManager : BaseManager
{
public:
    LoadManager() = default;
    LoadManager(const LoadManager &manager) = delete;
    auto operator = (const LoadManager &manager) -> LoadManager & = delete;

    ~LoadManager() = default;

    auto load(std::string &name) -> std::shared_ptr<Object>;
    auto loadScene(std::string &name) -> std::shared_ptr<Scene>;
    void setModerator(std::shared_ptr<BaseLoadModerator> moderator);
    void setSceneModerator(std::shared_ptr<SceneLoadModerator> moderator);

private:
    std::shared_ptr<BaseLoadModerator> _moderator;
    std::shared_ptr<SceneLoadModerator> _sceneModerator;
};

#endif // LOAD_MANAGER_H
