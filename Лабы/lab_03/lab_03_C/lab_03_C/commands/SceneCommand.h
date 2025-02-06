#ifndef SCENE_COMMAND_H
#define SCENE_COMMAND_H

#include <memory>
#include <string>

#include "BaseCommand.h"

class SceneCommand : public BaseCommand
{

};

class ClearScene : public SceneCommand
{
public:
    ClearScene(std::shared_ptr<BaseDrawer> drawer);
    void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};

class DrawScene : public SceneCommand
{
public:
    DrawScene(std::shared_ptr<BaseDrawer> drawer);
    void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};

class LoadScene : public SceneCommand
{
public:
    LoadScene(const std::string fileName);
    void execute() override;

private:
    std::string _fileName;

};

#endif // SCENE_COMMAND_H
