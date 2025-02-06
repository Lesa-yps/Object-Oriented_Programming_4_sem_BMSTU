#ifndef QT_DRAWER_FACTORY_H
#define QT_DRAWER_FACTORY_H

#include <QGraphicsScene>

#include "AbstractDrawerFactory.h"

class QtDrawerFactory : public AbstractDrawerFactory
{
public:
    explicit QtDrawerFactory(QGraphicsScene *scene);

    auto createDrawer() -> std::unique_ptr<BaseDrawer> override;

private:
    QGraphicsScene *_scene;
};

#endif // QT_DRAWER_FACTORY_H
