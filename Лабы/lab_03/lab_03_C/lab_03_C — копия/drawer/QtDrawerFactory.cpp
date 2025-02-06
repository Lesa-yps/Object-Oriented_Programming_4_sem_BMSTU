#include "QtDrawerFactory.h"
#include "QtDrawer.h"

QtDrawerFactory::QtDrawerFactory(QGraphicsScene *scene)
    : _scene(scene)
{

}

auto QtDrawerFactory::createDrawer() -> std::unique_ptr<BaseDrawer>
{
    return std::unique_ptr<BaseDrawer>(new QtDrawer(_scene));
}
