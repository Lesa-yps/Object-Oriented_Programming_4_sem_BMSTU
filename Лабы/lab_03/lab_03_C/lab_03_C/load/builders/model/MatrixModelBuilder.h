#ifndef MATRIXMODELBUILDER_H
#define MATRIXMODELBUILDER_H

#include "BaseModelBuilder.h"
#include "MatrixModelStructure.h"

class MatrixModelBuilder : public BaseModelBuilder
{
public:
    MatrixModelBuilder() = default;
    explicit MatrixModelBuilder(std::shared_ptr<BaseCarcassModelReader> reader);
    ~MatrixModelBuilder() = default;

    std::size_t buildVertexes() override;
    void buildEdges(std::size_t countVertex) override;

    std::shared_ptr<CarcassModel> get() override;
};

#endif // MATRIXMODELBUILDER_H
