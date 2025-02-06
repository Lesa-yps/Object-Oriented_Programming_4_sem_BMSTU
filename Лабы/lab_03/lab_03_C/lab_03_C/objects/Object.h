#ifndef OBJECT_H
#define OBJECT_H

#include <QDebug>

#include <memory>
#include <vector>

#include "Vertex.h"
#include "Transformer.h"

class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Object
{
public:
    Object();
    virtual ~Object() = default;

    virtual auto add(const std::shared_ptr<Object> &) -> bool;
    virtual auto remove(const Iterator &) -> bool;
    virtual void updateCenter();

    virtual auto isVisible() -> bool;
    virtual auto isComposite() -> bool;

    [[nodiscard]] virtual auto getCenter() const -> Vertex = 0;
    // убрать лишние transform-ы
    virtual void transform(Transformer &mtr, const Vertex &center) = 0;
    virtual void moveElemsToOrigin(const Vertex &) { }
    virtual void moveElemsToCenter(const Vertex &) { }

    virtual auto begin() -> Iterator;
    virtual auto end() -> Iterator;

    virtual auto getId() -> std::size_t;

protected:
    std::size_t _id;
    static std::size_t _nextId;
};

#endif //OBJECT_H
