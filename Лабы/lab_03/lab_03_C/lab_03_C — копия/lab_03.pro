#TARGET = lab_03

QT = core gui widgets

CONFIG += c++20

HEADERS = \
    adapters/BaseAdapter.h \
    adapters/composite/CompositeAdapter.h \
    adapters/composite/DrawCompositeAdapter.h \
    adapters/model/DrawCarcassModelAdapter.h \
    adapters/model/ModelAdapter.h \
    commands/BaseCommand.h \
    commands/CameraCommand.h \
    commands/ModelCommand.h \
    commands/ModelsCommand.h \
    commands/SceneCommand.h \
    concepts/ClassConcept.h \
    concepts/IteratorConcept.h \
    concepts/MatrixConcept.h \
    drawer/AbstractDrawerFactory.h \
    drawer/BaseDrawer.h \
    drawer/DrawerFactorySolution.h \
    drawer/DrawerFactorySolution.hpp \
    drawer/QtDrawer.h \
    drawer/QtDrawerFactory.h \
    exceptions/Exceptions.h \
    facade/Facade.h \
    load/builders/BaseBuilder.h \
    load/builders/camera/BaseCameraBuilder.h \
    load/builders/camera/CameraBuilder.h \
    load/builders/model/BaseModelBuilder.h \
    load/builders/model/ModelBuilder.h \
    load/builders/readers/BinFileCarcassModelReader.h \
    load/builders/readers/CarcassModelReaderFactory.h \
    load/builders/scene/BaseSceneBuilder.h \
    load/builders/scene/SceneBuilder.h \
    load/directors/BaseDirector.h \
    load/directors/camera/BaseCameraBuildDirector.h \
    load/directors/camera/FileCameraBuildDirector.h \
    load/directors/model/BaseModelBuildDirector.h \
    load/directors/model/FileModelBuildDirector.h \
    load/builders/readers/BaseCarcassModelReader.h \
    load/builders/readers/FileCarcassModelReader.h \
    load/builders/readers/CarcassModelReaderFactory.h \
    load/builders/readers/CarcassModelReaderFactory.cpp \
    load/directors/scene/BaseSceneBuildDirector.h \
    load/directors/scene/FileSceneBuildDirector.h \
    load/moderators/BaseLoadModerator.h \
    load/moderators/camera/CameraLoadModerator.h \
    load/moderators/creators/CameraLoadModeratorCreator.h \
    load/moderators/creators/ModelLoadModeratorCreator.h \
    load/moderators/creators/ModeratorSolution.h \
    load/moderators/creators/ModeratorSolution.hpp \
    load/moderators/creators/SceneLoadModeratorCreator.h \
    load/moderators/model/ModelLoadModerator.h \
    load/moderators/scene/SceneLoadModerator.h \
    managers/BaseManager.h \
    managers/BaseManagerCreator.h \
    managers/creators/DrawManagerCreator.h \
    managers/creators/LoadManagerCreator.h \
    managers/creators/ManagerSolution.h \
    managers/creators/ManagerSolution.hpp \
    managers/creators/SceneManagerCreator.h \
    managers/creators/TransformManagerCreator.h \
    managers/draw/DrawManager.h \
    managers/load/LoadManager.h \
    managers/scene/SceneManager.h \
    managers/transform/TransformManager.h \
    matrix/errors/errors.hpp \
    matrix/iterator/const_matrix_iterator.h \
    matrix/iterator/const_matrix_iterator.hpp \
    matrix/iterator/matrix_iterator.h \
    matrix/iterator/matrix_iterator.hpp \
    matrix/matrix/matrix_base.hpp \
    matrix/matrix/matrix.h \
    matrix/matrix/matrix.hpp \
    objects/Composite.h \
    objects/Object.h \
    objects/invisibleobject/Camera.h \
    objects/invisibleobject/InvisibleObject.h \
    objects/visibleobject/BaseModel.h \
    objects/visibleobject/VisibleObject.h \
    objects/visibleobject/carcassmodel/BaseModelStructure.h \
    objects/visibleobject/carcassmodel/CarcassModel.h \
    objects/visibleobject/carcassmodel/Edge.h \
    objects/visibleobject/carcassmodel/MatrixModelStructure.h \
    objects/visibleobject/carcassmodel/ModelStructure.h \
    objects/visibleobject/carcassmodel/Vertex.h \
    transform/Transformer.h \
    mainwindow.h \
    scene/Scene.h \
    transform/transformermove.h \
    transform/transformerrotate.h \
    transform/transformerscale.h

SOURCES = \
    adapters/composite/DrawCompositeAdapter.cpp \
    adapters/model/DrawCarcassModelAdapter.cpp \
    commands/BaseCommand.cpp \
    commands/CameraCommand.cpp \
    commands/ModelCommand.cpp \
    commands/ModelsCommand.cpp \
    commands/SceneCommand.cpp \
    drawer/QtDrawer.cpp \
    drawer/QtDrawerFactory.cpp \
    exceptions/Exceptions.cpp \
    facade/Facade.cpp \
    load/builders/camera/CameraBuilder.cpp \
    load/builders/model/BaseModelBuilder.cpp \
    load/builders/model/ModelBuilder.cpp \
    load/builders/readers/BinFileCarcassModelReader.cpp \
    load/builders/readers/CarcassModelReaderFactory.cpp \
    load/builders/scene/SceneBuilder.cpp \
    load/directors/camera/FileCameraBuildDirector.cpp \
    load/directors/model/FileModelBuildDirector.cpp \
    load/builders/readers/FileCarcassModelReader.cpp \
    load/directors/scene/FileSceneBuildDirector.cpp \
    load/moderators/camera/CameraLoadModerator.cpp \
    load/moderators/creators/CameraLoadModeratorCreator.cpp \
    load/moderators/creators/ModelLoadModeratorCreator.cpp \
    load/moderators/creators/SceneLoadModeratorCreator.cpp \
    load/moderators/model/ModelLoadModerator.cpp \
    load/moderators/scene/SceneLoadModerator.cpp \
    managers/creators/DrawManagerCreator.cpp \
    managers/creators/LoadManagerCreator.cpp \
    managers/creators/SceneManagerCreator.cpp \
    managers/creators/TransformManagerCreator.cpp \
    managers/draw/DrawManager.cpp \
    managers/load/LoadManager.cpp \
    managers/scene/SceneManager.cpp \
    managers/transform/TransformManager.cpp \
    matrix/errors/errors.cpp \
    matrix/matrix/matrix_base.cpp \
    objects/Composite.cpp \
    objects/Object.cpp \
    objects/invisibleobject/Camera.cpp \
    objects/visibleobject/carcassmodel/CarcassModel.cpp \
    objects/visibleobject/carcassmodel/Edge.cpp \
    objects/visibleobject/carcassmodel/MatrixModelStructure.cpp \
    objects/visibleobject/carcassmodel/ModelStructure.cpp \
    objects/visibleobject/carcassmodel/Vertex.cpp \
    transform/Transformer.cpp \
    main.cpp \
    mainwindow.cpp \
    scene/Scene.cpp \
    transform/transformermove.cpp \
    transform/transformerrotate.cpp \
    transform/transformerscale.cpp

FORMS += \
    mainwindow.ui

INCLUDEPATH = \
    . \
    adapters \
    adapters/composite \
    adapters/model \
    commands \
    concepts \
    drawer \
    exceptions \
    facade \
    load/builders \
    load/builders/camera \
    load/builders/model \
    load/builders/scene \
    load/directors \
    load/directors/camera \
    load/directors/model \
    load/directors/scene \
    load/builders/readers \
    load/moderators \
    load/moderators/camera \
    load/moderators/creators \
    load/moderators/model \
    load/moderators/scene \
    managers \
    managers/creators \
    managers/draw \
    managers/load \
    managers/scene \
    managers/transform \
    matrix \
    matrix/errors \
    matrix/iterator \
    matrix/matrix \
    objects \
    objects/invisibleobject \
    objects/visibleobject \
    objects/visibleobject/carcassmodel \
    transform \
    scene

#DEFINES =

DISTFILES += \
    data/cube.txt \
    data/tesseract.txt
