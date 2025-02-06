#ifndef BASE_MODEL_BUILD_DIRECTOR_H
#define BASE_MODEL_BUILD_DIRECTOR_H

#include "BaseDirector.h"
#include "ModelBuilder.h"

class BaseModelBuildDirector : public BaseDirector
{
public:
    virtual std::shared_ptr<CarcassModel> create(std::shared_ptr<BaseModelBuilder> builder) = 0;
};

#endif // BASE_MODEL_BUILD_DIRECTOR_H
