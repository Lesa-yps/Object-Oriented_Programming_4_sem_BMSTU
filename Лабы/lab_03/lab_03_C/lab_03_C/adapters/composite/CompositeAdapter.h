#ifndef COMPOSITE_ADAPTER_H
#define COMPOSITE_ADAPTER_H

#include "BaseAdapter.h"
#include "Composite.h"

class CompositeAdapter: public BaseAdapter
{
public:
    virtual ~CompositeAdapter() = default;

    void setAdaptee(std::shared_ptr<Composite> adaptee) { _adaptee = adaptee; }

    virtual void request() = 0;

protected:
    std::shared_ptr<Composite> _adaptee;
};

#endif // COMPOSITE_ADAPTER_H
