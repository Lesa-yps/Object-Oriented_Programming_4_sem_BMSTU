#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "Object.h"

class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    auto isVisible() -> bool override { return true; }
};

#endif //VISIBLEOBJECT_H
