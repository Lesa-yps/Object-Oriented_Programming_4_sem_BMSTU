#include "SceneCommand.h"

#include <utility>

ClearScene::ClearScene(std::shared_ptr<BaseDrawer> drawer)
    : _drawer(std::move(drawer))
{

};

void ClearScene::execute()
{
    _drawer->clearScene();
}

DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer)
    : _drawer(std::move(drawer))
{

};

void DrawScene::execute()
{
    _drawCompositeAdapter->setDrawer(_drawer);
    _drawManager->drawScene(_scene);
}

LoadScene::LoadScene(const std::string fileName)
    : _fileName(fileName)
{

};

void LoadScene::execute()
{
    _scene = _loadManager->loadScene(_fileName);
    _sceneManager->setScene(_scene);
}
