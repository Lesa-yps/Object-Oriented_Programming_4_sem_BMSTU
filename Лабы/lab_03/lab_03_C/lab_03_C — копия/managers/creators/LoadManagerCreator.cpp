#include "LoadManagerCreator.h"

auto LoadManagerCreator::createManager() -> std::shared_ptr<LoadManager>
{
    if (nullptr == _manager)
        createInstance();
    return _manager;
}

void LoadManagerCreator::createInstance()
{
    static std::shared_ptr<LoadManager> manager(new LoadManager());
    _manager = manager;
}
