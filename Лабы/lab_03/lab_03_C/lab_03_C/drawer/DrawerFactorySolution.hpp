#ifndef DRAWER_FACTORY_SOLUTION_HPP
#define DRAWER_FACTORY_SOLUTION_HPP

#include "DrawerFactorySolution.h"
#include "AbstractDrawerFactory.h"

template <Derivative<AbstractDrawerFactory> Tfactory, Derivative<QGraphicsScene> Tscene>
auto DrawerFactorySolution<Tfactory, Tscene>::createDrawer(Tscene *scene) -> std::unique_ptr<BaseDrawer>
{
    std::shared_ptr<AbstractDrawerFactory> factory(new Tfactory(scene));

    return factory->createDrawer();
}

#endif // DRAWER_FACTORY_SOLUTION_HPP
