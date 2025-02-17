#ifndef BASE_DRAWER_H
#define BASE_DRAWER_H

#include "Vertex.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Vertex &vertex1, const Vertex &vertex2) = 0;
    virtual void clearScene() = 0;
};

#endif // BASE_DRAWER_H
