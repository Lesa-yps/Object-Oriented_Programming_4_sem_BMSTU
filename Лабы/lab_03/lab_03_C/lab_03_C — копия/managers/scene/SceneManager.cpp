#include <utility>

#include "SceneManager.h"

SceneManager::SceneManager()
{
    _scene = std::make_shared<Scene>();
}

auto SceneManager::getScene() const -> std::shared_ptr<Scene>
{
    return _scene;
}

auto SceneManager::getCamera() const -> std::shared_ptr<Camera>
{
    return _camera;
}

void SceneManager::setScene(std::shared_ptr<Scene> scene)
{
    _scene = std::move(scene);
}

void SceneManager::setCamera(const std::size_t id)
{
    _camera = std::dynamic_pointer_cast<Camera>(*_scene->getObjectIter(id));
}
