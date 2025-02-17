#include "Facade.h"
#include "ManagerSolution.h"
#include "DrawManagerCreator.h"
#include "SceneManagerCreator.h"
#include "TransformManagerCreator.h"
#include "LoadManagerCreator.h"
#include "ModeratorSolution.h"
#include "ModelLoadModeratorCreator.h"
#include "SceneLoadModeratorCreator.h"
#include "CameraLoadModeratorCreator.h"

Facade::Facade()
{
    _drawManager = ManagerSolution<DrawManagerCreator>().create();
    _loadManager = ManagerSolution<LoadManagerCreator>().create();
    _sceneManager = ManagerSolution<SceneManagerCreator>().create();
    _transformManager = ManagerSolution<TransformManagerCreator>().create();

    _modelLoadModerator = ModeratorSolution<ModelLoadModeratorCreator>().create();
    _sceneLoadModerator = ModeratorSolution<SceneLoadModeratorCreator>().create();
    _cameraLoadModerator = ModeratorSolution<CameraLoadModeratorCreator>().create();

    _drawCompositeAdapter = std::make_shared<DrawCompositeAdapter>(DrawCompositeAdapter());
    _loadManager->setModerator(_modelLoadModerator);
    _loadManager->setSceneModerator(_sceneLoadModerator);
    _drawManager->setAdapter(_drawCompositeAdapter);
}

void Facade::execute(BaseCommand &command)
{
    command.setManagers(_drawManager, _loadManager, _sceneManager, _transformManager, _modelLoadModerator, _sceneLoadModerator, _cameraLoadModerator, _drawCompositeAdapter);
    auto camera = _sceneManager->getCamera();
    _drawCompositeAdapter->setCamera(camera);
    auto scene = _sceneManager->getScene();
    command.setScene(scene);
    command.execute();
}
