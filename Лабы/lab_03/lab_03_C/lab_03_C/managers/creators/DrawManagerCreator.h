#ifndef DRAW_MANAGER_CREATOR_H
#define DRAW_MANAGER_CREATOR_H

#include "BaseManagerCreator.h"
#include "DrawManager.h"

class DrawManagerCreator : public BaseManagerCreator
{
public:
    auto createManager() -> std::shared_ptr<DrawManager>;

private:
    void createInstance();

    std::shared_ptr<DrawManager> _manager;
};

#endif // DRAW_MANAGER_CREATOR_H
