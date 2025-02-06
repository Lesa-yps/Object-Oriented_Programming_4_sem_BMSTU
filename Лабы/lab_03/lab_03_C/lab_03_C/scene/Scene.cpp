#include <QDebug>

#include "Scene.h"
#include "Composite.h"
#include "Camera.h"

Scene::Scene() : _allObjects() { }

auto Scene::addObject(const std::shared_ptr<Object>& object) -> std::size_t
{
    _allObjects.push_back(object);
    return object->getId();
}

auto Scene::addCamera(const Vertex& location) -> std::size_t
{
    auto camera = std::make_shared<Camera>(Camera(location));
    _allObjects.push_back(camera);
    return camera->getId();
}

void Scene::deleteObject(Iterator &iter)
{
    _allObjects.erase(iter);
}

auto Scene::getObjectIter(std::size_t id) -> Iterator
{
    return std::find_if(_allObjects.begin(), _allObjects.end(), [id](const std::shared_ptr<Object>& obj) {
        return obj->getId() == id;
    });
}

auto Scene::getObject(const std::size_t id) -> std::shared_ptr<Object>
{
    return *getObjectIter(id);
}

auto Scene::getVisibleObjects() -> std::shared_ptr<Composite>
{
    std::shared_ptr<Composite> visibleObjects = std::make_shared<Composite>();
    for (const auto& obj : _allObjects)
        if (obj->isVisible())
            visibleObjects->add(obj);
    return visibleObjects;
}

auto Scene::getInvisibleObjects() -> std::shared_ptr<Composite>
{
    std::shared_ptr<Composite> invisibleObjects = std::make_shared<Composite>();
    for (const auto& obj : _allObjects)
        if (! obj->isVisible())
            invisibleObjects->add(obj);
    return invisibleObjects;
}
