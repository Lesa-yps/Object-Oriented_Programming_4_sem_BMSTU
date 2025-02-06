#include "TransformManager.h"

void TransformManager::moveObject(const std::shared_ptr <Object> &object, const double &dx, const double &dy, const double &dz)
{
    //Transformer mtr(dx, dy, dz, 1, 1, 1, 0, 0, 0);
    TransformerMove mtr(dx, dy, dz);
    object->updateCenter();
    object->transform(mtr, object->getCenter());
}

void TransformManager::scaleObject(const std::shared_ptr <Object> &object, const double &kx, const double &ky, const double &kz)
{
    //Transformer mtr = Transformer(0, 0, 0, kx, ky, kz, 0, 0, 0);
    TransformerScale mtr(kx, ky, kz);
    object->updateCenter();
    object->transform(mtr, object->getCenter());
}

void TransformManager::rotateObject(const std::shared_ptr <Object> &object, const double &ax, const double &ay, const double &az)
{
    //Transformer mtr = Transformer(0, 0, 0, 1, 1, 1, ax, ay, az);
    TransformerRotate mtr(ax, ay, az);
    object->updateCenter();
    object->transform(mtr, object->getCenter());
}

void TransformManager::transformObject(const std::shared_ptr<Object> &object, Transformer &mtr)
{
    object->updateCenter();
    object->transform(mtr, object->getCenter());
}
