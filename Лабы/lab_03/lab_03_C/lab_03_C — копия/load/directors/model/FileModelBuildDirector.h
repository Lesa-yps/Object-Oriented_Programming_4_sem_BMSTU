#ifndef FILE_MODEL_BUILD_DIRECTOR_H
#define FILE_MODEL_BUILD_DIRECTOR_H

#include "BaseModelBuildDirector.h"
#include "FileCarcassModelReader.h"
#include "ModelBuilder.h"
#include <memory>
#include <vector>
#include <string>

class FileModelBuildDirector : public BaseModelBuildDirector
{
public:
    FileModelBuildDirector();
    ~FileModelBuildDirector() override = default;

    std::shared_ptr<CarcassModel> create(std::shared_ptr<BaseModelBuilder> builder) override;
};

#endif // FILE_MODEL_BUILD_DIRECTOR_H
