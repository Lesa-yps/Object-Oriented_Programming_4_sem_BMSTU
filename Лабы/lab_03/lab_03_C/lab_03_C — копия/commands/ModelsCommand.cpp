#include "ModelsCommand.h"

MoveModels::MoveModels(const double dx, const double dy, const double dz)
    : _dx(dx), _dy(dy), _dz(dz)
{

};

void MoveModels::execute()
{
    _transformManager->moveObject(_scene->getVisibleObjects(), _dx, _dy, _dz);
}

ScaleModels::ScaleModels(const double kx, const double ky, const double kz)
    : _kx(kx), _ky(ky), _kz(kz)
{

};

void ScaleModels::execute()
{
    _transformManager->scaleObject(_scene->getVisibleObjects(), _kx, _ky, _kz);
}


RotateModels::RotateModels(const double ax, const double ay, const double az)
    : _ax(ax), _ay(ay), _az(az)
{

};

void RotateModels::execute()
{
    _transformManager->rotateObject(_scene->getVisibleObjects(), _ax, _ay, _az);
}

TransformModels::TransformModels(Transformer &mtr) :
    _mtr(mtr) { }

void TransformModels::execute()
{
    _transformManager->transformObject(_scene->getVisibleObjects(), _mtr);
}
