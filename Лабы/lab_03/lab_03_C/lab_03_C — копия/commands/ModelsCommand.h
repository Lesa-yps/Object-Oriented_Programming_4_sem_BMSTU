#ifndef MODELS_COMMAND_H
#define MODELS_COMMAND_H

#include "BaseCommand.h"
#include "Transformer.h"

class ModelsCommand : public BaseCommand
{

};

class MoveModels : public ModelsCommand
{
public:
    MoveModels(const double dx, const double dy, const double dz);
    void execute() override;

private:
    double _dx, _dy, _dz;
};

class ScaleModels : public ModelsCommand
{
public:
    ScaleModels(const double kx, const double ky, const double kz);
    void execute() override;

private:
    double _kx, _ky, _kz;
};

class RotateModels : public ModelsCommand
{
public:
    RotateModels(const double ax, const double ay, const double az);
    void execute() override;

private:
    double _ax, _ay, _az;
};

class TransformModels : public ModelsCommand
{
public:
    TransformModels(Transformer &mtr);
    void execute() override;

private:
    Transformer _mtr;
};

#endif // MODELS_COMMAND_H
