#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "Object.h"
#include "TransformerMove.h"

class Composite : public Object
{
    friend class DrawCompositeAdapter;

public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object> &element);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &elements);

    auto add(const std::shared_ptr<Object> &element) -> bool override;
    auto remove(const Iterator &iter) -> bool override;
    void updateCenter() override;

    auto isVisible() -> bool override;
    auto isComposite() -> bool override;

    [[nodiscard]] auto getCenter() const -> Vertex override;
    virtual void transform(Transformer &mtr, const Vertex &center) override;

    auto begin() -> Iterator override;
    auto end() -> Iterator override;

protected:
    void moveElemsToOrigin(const Vertex &center) override;
    void moveElemsToCenter(const Vertex &center) override;
    void transformElems(Transformer &mtr);

private:
    Vertex _center;
    std::vector<std::shared_ptr<Object>> _elements;
};

#endif //COMPOSITE_H
