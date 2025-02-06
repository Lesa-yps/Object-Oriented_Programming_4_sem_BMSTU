#ifndef MODEL_COMMAND_H
#define MODEL_COMMAND_H

#include <cstddef>
#include <memory>

#include "BaseCommand.h"
#include "Transformer.h"

using ID = std::shared_ptr<std::size_t>;

class ModelCommand : public BaseCommand
{

};

class MoveModel : public ModelCommand
{
public:
    MoveModel(const double dx, const double dy, const double dz, const std::size_t id);
    void execute() override;

private:
    double _dx, _dy, _dz;
    std::size_t _id;
};


class ScaleModel : public ModelCommand
{
public:
    ScaleModel(const double kx, const double ky, const double kz, const std::size_t id);
    void execute() override;

private:
    double _kx, _ky, _kz;
    std::size_t _id;
};

class RotateModel : public ModelCommand
{
public:
    RotateModel(const double ax, const double ay, const double az, const std::size_t id);
    void execute() override;

private:
    double _ax, _ay, _az;
    std::size_t _id;
};

class TransformModel : public ModelCommand
{
public:
    TransformModel(Transformer &mtr, const std::size_t id);
    void execute() override;

private:
    Transformer _mtr;
    std::size_t _id;
};

class DeleteModel : public ModelCommand
{
public:
    DeleteModel(const std::size_t id);
    void execute() override;

private:
    std::size_t _id;
};

class LoadModel : public ModelCommand
{
public:
    LoadModel(ID id, std::string &fileName);
    void execute() override;

private:
    std::string _fileName;
    ID _id;
};

#endif // MODEL_COMMAND_H
