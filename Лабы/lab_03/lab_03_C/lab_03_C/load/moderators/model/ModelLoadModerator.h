#ifndef MODEL_LOAD_MODERATOR_H
#define MODEL_LOAD_MODERATOR_H

#include "BaseLoadModerator.h"
#include "BaseModelBuildDirector.h"
#include "FileCarcassModelReader.h"
#include "CarcassModelReaderFactory.h"


class ModelLoadModerator : public BaseLoadModerator
{
public:
    ModelLoadModerator() = default;
    explicit ModelLoadModerator(std::shared_ptr<BaseModelBuildDirector> director);

    ~ModelLoadModerator() = default;

    std::shared_ptr<Object> load(const std::string &fileName) override;

private:
    std::shared_ptr<BaseModelBuildDirector> _director;
};


#endif // MODEL_LOAD_MODERATOR_H
