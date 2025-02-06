#include "SceneManagerCreator.h"

auto SceneManagerCreator::createManager() -> std::shared_ptr<SceneManager>
{
    if (nullptr == _manager)
        createInstance();
    return _manager;
}

void SceneManagerCreator::createInstance()
{
    static std::shared_ptr<SceneManager> manager(new SceneManager());
    _manager = manager;
}
