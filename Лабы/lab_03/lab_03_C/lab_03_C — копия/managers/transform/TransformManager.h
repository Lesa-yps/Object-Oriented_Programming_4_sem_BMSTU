#ifndef TRANSFORM_MANAGER_H
#define TRANSFORM_MANAGER_H

#include <memory.h>

#include "BaseManager.h"
#include "Object.h"
#include "Matrix.h"
#include "TransformerMove.h"
#include "TransformerRotate.h"
#include "TransformerScale.h"

class TransformManager : public BaseManager
{
public:
    TransformManager() = default;
    TransformManager(const TransformManager &manager) = delete;
    auto operator = (const TransformManager &manager) -> TransformManager & = delete;

    ~TransformManager() = default;

    static void moveObject(const std::shared_ptr<Object> &object, const double &dx, const double &dy, const double &dz);
    static void scaleObject(const std::shared_ptr<Object> &object, const double &kx, const double &ky, const double &kz);
    static void rotateObject(const std::shared_ptr<Object> &object, const double &ax, const double &ay, const double &az);
    static void transformObject(const std::shared_ptr<Object> &object, Transformer &mtr);
};

#endif // TRANSFORM_MANAGER_H
