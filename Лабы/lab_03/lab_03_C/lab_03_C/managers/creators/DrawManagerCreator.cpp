#include "DrawManagerCreator.h"

auto DrawManagerCreator::createManager() -> std::shared_ptr<DrawManager>
{
    if (nullptr == _manager)
        createInstance();
    return _manager;
}

void DrawManagerCreator::createInstance()
{
    static std::shared_ptr<DrawManager> manager(new DrawManager());
    _manager = manager;
}
