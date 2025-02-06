#ifndef SCENE_H
#define SCENE_H

#include "Composite.h"
#include "Vertex.h"
#include "Object.h"

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Scene
{
public:
    Scene();
    ~Scene() = default;

    auto addObject(const std::shared_ptr<Object> &object) -> std::size_t;
    auto addCamera(const Vertex &location) -> std::size_t;
    void deleteObject(Iterator &iter);

    auto getObjectIter(const std::size_t id) -> Iterator;
    auto getObject(const std::size_t id) -> std::shared_ptr<Object>;

    auto getVisibleObjects() -> std::shared_ptr<Composite>;
    auto getInvisibleObjects() -> std::shared_ptr<Composite>;

protected:
    // объединить в 1 shared_ptr на Object
    std::vector<std::shared_ptr<Object>> _allObjects;
};

#endif // SCENE_H
