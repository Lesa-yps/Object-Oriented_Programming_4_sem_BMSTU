#include "SceneLoadModerator.h"
#include "Exceptions.h"

SceneLoadModerator::SceneLoadModerator(std::shared_ptr<BaseSceneBuildDirector> director)
    : _director(std::move(director)) { }

std::shared_ptr<Scene> SceneLoadModerator::load(const std::string &fileName)
{
    CarcassModelReaderFactory CMreaderFactory;
    auto reader = CMreaderFactory.createReader(fileName);
    auto builder = std::make_shared<SceneBuilder>(reader);
    return _director->create(builder);
}
