#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CameraCommand.h"
#include "ModelCommand.h"
#include "ModelsCommand.h"
#include "SceneCommand.h"
#include "Exceptions.h"
#include "DrawerFactorySolution.h"
#include "QtDrawerFactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();
    _facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupScene()
{
    _scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    auto cont = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, cont.width(), cont.height());
    _camInd = 1;
    auto solution(new DrawerFactorySolution<QtDrawerFactory, QGraphicsScene>());
    _drawer = solution->createDrawer(_scene);
}

void MainWindow::updateScene()
{
    ClearScene clear_cmd(_drawer);
    _facade->execute(clear_cmd);
    DrawScene draw_cmd(_drawer);
    _facade->execute(draw_cmd);
}

void MainWindow::checkCamExist()
{
    if (!_cameras.size())
    {
        throw CameraException("No camera found.");
    }
}

void MainWindow::checkModelsExist()
{
    if (!_models.size())
    {
        throw ModelException("No models found.");
    }
}

void MainWindow::checkCamDelete()
{
    if (_cameras.size() <= 1 && _models.size())
    {
        throw CameraException("Can not delete the last camera with the loaded models");
    }
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();
    auto id = std::make_shared<size_t>(0);
    Vertex location(cont.width() / 2.0, cont.height() / 2.0, 0.0);
    AddCamera addCMD(id, location);
    _facade->execute(addCMD);
    _cameras.push_back(*id);
    updateScene();
    auto cam = ui->cameraCB;
    std::string camName = std::string("cam") + std::to_string(_camInd++);
    cam->addItem(QString(camName.data()));
    ui->cameraCB->setCurrentIndex(ui->cameraCB->count() - 1);
}

void MainWindow::on_loadModelBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Добавьте камеру!");
        return;
    }

    auto file = QFileDialog::getOpenFileName(nullptr, "Загрузка модели", "F:/OOP/lab_03_C/data");
    if (file.isNull())
        return;

    auto id = std::make_shared<size_t>(0);
    std::string fileName = file.toStdString();
    LoadModel cmd(id, fileName);

    try
    {
        _facade->execute(cmd);
    }
    catch (const BaseException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка при загрузке файла!");
        return;
    }

    _models.push_back(*id);
    updateScene();
    ui->modelsCB->addItem(QFileInfo(file.toUtf8().data()).fileName());
    ui->modelsCB->setCurrentIndex(ui->modelsCB->count() - 1);
}

void MainWindow::on_deleteModelBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    std::size_t id = _models.at(ui->modelsCB->currentIndex());
    DeleteModel cmd(id);
    _facade->execute(cmd);
    _models.erase(_models.begin() + ui->modelsCB->currentIndex());
    ui->modelsCB->removeItem(ui->modelsCB->currentIndex());
    updateScene();
}

void MainWindow::on_deleteModelsBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    for (int i = ui->modelsCB->count() - 1; i >= 0; --i)
    {
        std::size_t id = _models.at(i);
        DeleteModel cmd(id);
        _facade->execute(cmd);
        _models.erase(_models.begin() + i);
        ui->modelsCB->removeItem(i);
    }

    updateScene();
}

void MainWindow::on_cameraCB_currentIndexChanged(int index)
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    std::size_t id = _cameras.at(index);
    SetCamera cmd(id);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_deleteCameraBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }

    try
    {
        checkCamDelete();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Это последняя камера! Для удаления удалите модели!");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    DeleteCamera cmd(id);
    _facade->execute(cmd);
    _cameras.erase(_cameras.begin() + ui->cameraCB->currentIndex());
    ui->cameraCB->removeItem(ui->cameraCB->currentIndex());

    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    updateScene();
}

#define MOVE_DELTA 10

void MainWindow::on_upBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    MoveCamera cmd(0, MOVE_DELTA, 0, id);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_rigthBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    MoveCamera cmd(-MOVE_DELTA, 0, 0, id);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_downBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    MoveCamera cmd(0, -MOVE_DELTA, 0, id);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_leftBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    MoveCamera cmd(MOVE_DELTA, 0, 0, id);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_moveBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    MoveModel cmd(ui->dxDSB->value(), ui->dyDSB->value(), ui->dzDSB->value(), _models.at(ui->modelsCB->currentIndex()));
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_moveAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    MoveModels cmd(ui->dxDSB->value(), ui->dyDSB->value(), ui->dzDSB->value());
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_scaleBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    ScaleModel cmd(ui->kxDSB->value(), ui->kyDSB->value(), ui->kzDSB->value(), _models.at(ui->modelsCB->currentIndex()));
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_scaleAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    ScaleModels cmd(ui->kxDSB->value(), ui->kyDSB->value(), ui->kzDSB->value());
    _facade->execute(cmd);
    updateScene();
}

#define TO_RAD_COEF (M_PI / 180)

void MainWindow::on_rotateBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    RotateModel cmd(ui->oxDSB->value() * TO_RAD_COEF, ui->oyDSB->value() * TO_RAD_COEF, ui->ozDSB->value() * TO_RAD_COEF, _models.at(ui->modelsCB->currentIndex()));
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_rotateAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    RotateModels cmd(ui->oxDSB->value() * TO_RAD_COEF, ui->oyDSB->value() * TO_RAD_COEF, ui->ozDSB->value() * TO_RAD_COEF);
    _facade->execute(cmd);
    updateScene();
}


void MainWindow::on_menu_author_triggered()
{
    QMessageBox::information(0, "Информация об авторе", "Программу разработала студентка группы ИУ7-45Б Талышева Олеся.");
}


void MainWindow::on_menu_task_triggered()
{
    QMessageBox::information(0, "Информация о задании", "Программа позволяет загрузить и выгрузить в файл, промасштабировать,\
 перенести и повернуть 3Д объект.");
}
