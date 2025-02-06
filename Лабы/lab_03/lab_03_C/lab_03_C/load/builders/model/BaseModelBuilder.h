#ifndef BASE_MODEL_BUILDER_H
#define BASE_MODEL_BUILDER_H

#include "BaseModelStructure.h"
#include "CarcassModel.h"
#include "BaseBuilder.h"
#include "BaseCarcassModelReader.h"

class BaseModelBuilder : public BaseBuilder
{
public:

    virtual std::size_t buildVertexes() = 0;
    virtual void buildEdges(std::size_t countVertex) = 0;

    virtual std::shared_ptr<CarcassModel> get() = 0;

protected:
    std::shared_ptr<BaseCarcassModelReader> _reader;
    std::shared_ptr<BaseModelStructure> _model { nullptr };
};

#endif // BASE_MODEL_BUILDER_H
