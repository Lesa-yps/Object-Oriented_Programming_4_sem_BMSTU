#ifndef CARCASS_MODEL_H
#define CARCASS_MODEL_H

#include <memory>

#include "BaseModel.h"
#include "BaseModelStructure.h"
#include "DrawCarcassModelAdapter.h"
#include "Object.h"


class CarcassModel : public BaseModel
{
    friend class DrawCarcassModelAdapter;

public:
    CarcassModel() : _modelStructure(nullptr) { }
    explicit CarcassModel(const std::shared_ptr<BaseModelStructure> &modelStructure) : _modelStructure(modelStructure) { }
    CarcassModel(const CarcassModel &model);

    ~CarcassModel() override = default;

    virtual Vertex getCenter() const override;
    virtual void transform(Transformer &mtr, const Vertex &center) override;

protected:
    std::shared_ptr<BaseModelStructure> _modelStructure;
};

#endif // CARCASS_MODEL_H
