#ifndef BASE_SCENE_BUILDER_H
#define BASE_SCENE_BUILDER_H

#include "Scene.h"
#include "BaseCarcassModelReader.h"
#include "BaseBuilder.h"

class BaseSceneBuilder : public BaseBuilder
{
public:
    BaseSceneBuilder() = default;
    explicit BaseSceneBuilder(std::shared_ptr<BaseCarcassModelReader> &reader) : _reader(reader) {}
    virtual ~BaseSceneBuilder() = default;

    virtual void buildModels() = 0;
    virtual void buildCameras() = 0;

    virtual std::shared_ptr<Scene> get() = 0;

protected:
    std::shared_ptr<BaseCarcassModelReader> _reader;
    std::shared_ptr<Scene> _scene;
};

#endif // BASE_SCENE_BUILDER_H
