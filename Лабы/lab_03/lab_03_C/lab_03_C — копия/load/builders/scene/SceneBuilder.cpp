#include "SceneBuilder.h"

SceneBuilder::SceneBuilder(std::shared_ptr<BaseCarcassModelReader> reader)
{
    _reader = reader;
    _scene = std::make_shared<Scene>();
}

void SceneBuilder::buildModels()
{
    size_t countModels = _reader->readCount();
    auto modBuilder = std::make_shared<ModelBuilder>();
    for (size_t i = 0; i < countModels; i++)
    {
        auto model = FileModelBuildDirector().create(modBuilder);
        _scene->addObject(model);
    }
}

void SceneBuilder::buildCameras()
{
    size_t countCameras = _reader->readCount();
    auto camBuilder = std::make_shared<CameraBuilder>();
    for (size_t i = 0; i < countCameras; i++)
    {
        auto camera = FileCameraBuildDirector().create(camBuilder);
        _scene->addObject(camera);
    }
}

std::shared_ptr<Scene> SceneBuilder::get()
{
    return _scene;
}
