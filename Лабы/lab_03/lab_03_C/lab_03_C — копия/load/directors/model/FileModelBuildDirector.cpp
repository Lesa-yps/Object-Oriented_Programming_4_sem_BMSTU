#include "FileModelBuildDirector.h"
#include "exceptions.h"
#include "ModelBuilder.h"

FileModelBuildDirector::FileModelBuildDirector() {}


std::shared_ptr<CarcassModel> FileModelBuildDirector::create(std::shared_ptr<BaseModelBuilder> builder)
{
    auto countVertex = builder->buildVertexes();
    builder->buildEdges(countVertex);
    return builder->get();
}
