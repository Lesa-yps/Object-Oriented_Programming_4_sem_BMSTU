#ifndef BASE_MODEL_BUILDER_H
#define BASE_MODEL_BUILDER_H

#include "ModelStructure.h"
#include "CarcassModel.h"
#include "BaseBuilder.h"
#include "BaseCarcassModelReader.h"

class BaseModelBuilder : public BaseBuilder
{
public:
    BaseModelBuilder() = default;
    explicit BaseModelBuilder(std::shared_ptr<BaseCarcassModelReader> &reader);
    virtual ~BaseModelBuilder() = default;

    virtual std::size_t buildVertexes() = 0;
    virtual void buildEdges(std::size_t countVertex) = 0;

    virtual std::shared_ptr<CarcassModel> get() = 0;

protected:
    std::shared_ptr<BaseCarcassModelReader> _reader;
    std::shared_ptr<ModelStructure> _model;
};

#endif // BASE_MODEL_BUILDER_H
