#ifndef TRANSFORM_MANAGER_CREATOR_H
#define TRANSFORM_MANAGER_CREATOR_H

#include "BaseManagerCreator.h"
#include "TransformManager.h"

class TransformManagerCreator : public BaseManagerCreator
{
public:
    std::shared_ptr<TransformManager> createManager();

private:
    void createInstance();

    std::shared_ptr<TransformManager> _manager;
};

#endif // TRANSFORM_MANAGER_CREATOR_H
