#ifndef MODEL_ADAPTER_H
#define MODEL_ADAPTER_H

#include "BaseAdapter.h"
#include "CarcassModel.h"

class CarcassModel;

class ModelAdapter: public BaseAdapter
{
public:
    virtual ~ModelAdapter() = default;

    void setAdaptee(std::shared_ptr<CarcassModel> adaptee) {_adaptee = adaptee;};

    virtual void request() = 0;

protected:
    std::shared_ptr<CarcassModel> _adaptee;
};

#endif // MODEL_ADAPTER_H
