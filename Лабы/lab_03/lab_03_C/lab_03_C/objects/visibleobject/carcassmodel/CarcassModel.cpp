#include "CarcassModel.h"

CarcassModel::CarcassModel(const CarcassModel &model)
    : _modelStructure(model._modelStructure)
{
    _id = model._id;
}

Vertex CarcassModel::getCenter() const
{
    return _modelStructure->getCenter();
}

void CarcassModel::transform(Transformer &mtr, const Vertex &center)
{
    _modelStructure->transform(mtr, center);
}
