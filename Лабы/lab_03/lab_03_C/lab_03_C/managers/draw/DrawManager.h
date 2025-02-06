#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include <memory>

#include "BaseManager.h"
#include "Composite.h"
#include "Scene.h"
#include "DrawCompositeAdapter.h"

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    auto operator = (const DrawManager &manager) -> DrawManager & = delete;

    ~DrawManager() = default;

    void setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter);
    void drawScene(std::shared_ptr<Scene> scene);

private:
    std::shared_ptr<DrawCompositeAdapter> _adapter;
};

#endif // DRAW_MANAGER_H
