#include "ModelLoadModerator.h"
#include "Exceptions.h"
#include "MatrixModelBuilder.h"


ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelBuildDirector> director)
    : _director(director) { }

std::shared_ptr<Object> ModelLoadModerator::load(const std::string &fileName)
{
    CarcassModelReaderFactory CMreaderFactory;
    auto reader = CMreaderFactory.createReader(fileName);
    auto builder = std::make_shared<MatrixModelBuilder>(reader);
    return _director->create(builder);
}
