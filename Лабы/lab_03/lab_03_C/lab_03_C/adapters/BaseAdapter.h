#ifndef BASE_ADAPTER_H
#define BASE_ADAPTER_H

class BaseAdapter
{
public:
    virtual ~BaseAdapter() = default;

    virtual void request() = 0;
};

#endif // BASE_ADAPTER_H
