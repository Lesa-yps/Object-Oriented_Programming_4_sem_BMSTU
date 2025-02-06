#ifndef SCENE_BUILDER_H
#define SCENE_BUILDER_H

#include "BaseSceneBuilder.h"
#include "FileModelBuildDirector.h"
#include "FileCameraBuildDirector.h"

class SceneBuilder : public BaseSceneBuilder
{
public:
    SceneBuilder() = default;
    explicit SceneBuilder(std::shared_ptr<BaseCarcassModelReader> reader);
    ~SceneBuilder() = default;

    void buildModels() override;
    void buildCameras() override;

    std::shared_ptr<Scene> get() override;
};

#endif // SCENE_BUILDER_H
