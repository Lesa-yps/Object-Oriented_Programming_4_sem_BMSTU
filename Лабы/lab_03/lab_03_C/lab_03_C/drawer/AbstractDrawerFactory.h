#ifndef ABSTRACT_DRAWER_FACTORY_H
#define ABSTRACT_DRAWER_FACTORY_H

#include <memory>

#include "BaseDrawer.h"

class AbstractDrawerFactory
{
public:
    virtual auto createDrawer() -> std::unique_ptr<BaseDrawer> = 0;
};

#endif // ABSTRACT_DRAWER_FACTORY_H
