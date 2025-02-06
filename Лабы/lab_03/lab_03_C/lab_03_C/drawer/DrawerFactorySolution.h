#ifndef DRAWER_FACTORY_SOLUTION_H
#define DRAWER_FACTORY_SOLUTION_H

#include "ClassConcept.h"
#include "BaseDrawer.h"
#include "AbstractDrawerFactory.h"

template <Derivative<AbstractDrawerFactory> Tfactory, Derivative<QGraphicsScene> Tscene>
class DrawerFactorySolution
{
public:
    auto createDrawer(Tscene *scene) -> std::unique_ptr<BaseDrawer>;
};

#include "DrawerFactorySolution.hpp"

#endif // DRAWER_FACTORY_SOLUTION_H
