#ifndef QT_DRAWER_H
#define QT_DRAWER_H

#include <QGraphicsScene>

#include "BaseDrawer.h"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = delete;
    explicit QtDrawer(QGraphicsScene *scene);
    QtDrawer(const QtDrawer &drawer);

    void drawLine(const Vertex &vertex1, const Vertex &vertex2) override;
    void clearScene() override;

private:
    QGraphicsScene *_scene;
};

#endif // QT_DRAWER_H
