#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "Object.h"

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;

    auto isVisible() -> bool override { return false; }
};

#endif //INVISIBLEOBJECT_H
