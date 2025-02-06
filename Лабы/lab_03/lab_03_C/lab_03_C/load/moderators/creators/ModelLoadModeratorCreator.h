#ifndef MODEL_LOAD_MODERATOR_CREATOR_H
#define MODEL_LOAD_MODERATOR_CREATOR_H

#include "ModelLoadModerator.h"

class ModelLoadModeratorCreator
{
public:
    std::shared_ptr<ModelLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<ModelLoadModerator> _moderator;
};

#endif // MODEL_LOAD_MODERATOR_CREATOR_H
