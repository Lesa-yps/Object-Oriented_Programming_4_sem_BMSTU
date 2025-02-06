#include "FileSceneBuildDirector.h"

std::shared_ptr<Scene> FileSceneBuildDirector::create(std::shared_ptr<SceneBuilder> builder)
{
    builder->buildModels();
    builder->buildCameras();
    return builder->get();
}
