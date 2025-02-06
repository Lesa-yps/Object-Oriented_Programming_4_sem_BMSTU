#include <QDebug>
#include <utility>

#include "ModelCommand.h"

MoveModel::MoveModel(const double dx, const double dy, const double dz, const std::size_t id)
    : _dx(dx), _dy(dy), _dz(dz), _id(id)
{

};

void MoveModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->moveObject(model, _dx, _dy, _dz);
}

ScaleModel::ScaleModel(const double kx, const double ky, const double kz, const std::size_t id)
    : _kx(kx), _ky(ky), _kz(kz), _id(id)
{

};

void ScaleModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->scaleObject(model, _kx, _ky, _kz);
}

RotateModel::RotateModel(const double ax, const double ay, const double az, const std::size_t id)
    : _ax(ax), _ay(ay), _az(az), _id(id)
{

};

void RotateModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->rotateObject(model, _ax, _ay, _az);
}

TransformModel::TransformModel(Transformer &mtr, const std::size_t id) :
    _mtr(mtr), _id(id) { }

void TransformModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->transformObject(model, _mtr);
}

DeleteModel::DeleteModel(const std::size_t id)
    : _id(id)
{

};

void DeleteModel::execute()
{
    auto objIt = _scene->getObjectIter(_id);
    _scene->deleteObject(objIt);
}

LoadModel::LoadModel(ID id, std::string &fileName)
    : _fileName(fileName), _id(std::move(id))
{

};

void LoadModel::execute()
{
    auto model = _loadManager->load(_fileName);
    (*_id) = _scene->addObject(model);
}
