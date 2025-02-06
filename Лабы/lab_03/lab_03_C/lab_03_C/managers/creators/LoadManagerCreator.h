#ifndef LOAD_MANAGER_CREATOR_H
#define LOAD_MANAGER_CREATOR_H

#include <memory>

#include "BaseManagerCreator.h"
#include "LoadManager.h"

class LoadManagerCreator : public BaseManagerCreator
{
public:
    auto createManager() -> std::shared_ptr<LoadManager>;

private:
    void createInstance();

    std::shared_ptr<LoadManager> _manager;
};

#endif // LOAD_MANAGER_CREATOR_H
