#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <memory>

#include "BaseManager.h"
#include "Scene.h"
#include "Camera.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager &scene) = delete;
    auto operator = (const SceneManager &scene) -> SceneManager & = delete;

    ~SceneManager() = default;

    [[nodiscard]] auto getScene() const -> std::shared_ptr<Scene>;
    [[nodiscard]] auto getCamera() const -> std::shared_ptr<Camera>;
    void setScene(std::shared_ptr<Scene> scene);
    void setCamera(const std::size_t id);

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<Scene> _scene;
};

#endif // SCENE_MANAGER_H
