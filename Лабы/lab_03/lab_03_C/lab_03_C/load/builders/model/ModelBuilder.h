#ifndef MODEL_BUILDER_H
#define MODEL_BUILDER_H

#include "BaseModelBuilder.h"
#include "ModelStructure.h"

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;
    explicit ModelBuilder(std::shared_ptr<BaseCarcassModelReader> reader);
    ~ModelBuilder() = default;

    std::size_t buildVertexes() override;
    void buildEdges(std::size_t countVertex) override;

    std::shared_ptr<CarcassModel> get() override;
};

#endif // BUILDER_MODEL_H
