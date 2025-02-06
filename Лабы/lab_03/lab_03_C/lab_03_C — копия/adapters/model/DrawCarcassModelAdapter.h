#ifndef DRAW_CARCASS_MODEL_ADAPTER_H
#define DRAW_CARCASS_MODEL_ADAPTER_H

#include "ModelAdapter.h"
#include "Camera.h"
#include "BaseDrawer.h"

class Camera;

class DrawCarcassModelAdapter : public ModelAdapter
{
public:
    void setCamera(std::shared_ptr<Camera> camera);
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);
    void request() override;
    auto getProjection(const Vertex &vertex) -> Vertex;

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;
};

#endif // DRAW_CARCASS_MODEL_ADAPTER_H
