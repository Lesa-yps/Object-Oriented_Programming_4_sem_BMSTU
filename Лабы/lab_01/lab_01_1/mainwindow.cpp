#include "mainwindow.h"

QGraphicsScene *scene;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene();
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    request_t request;
    request.action = LOAD;
    request.filename = "cube.txt";
    error_t rc = task_manager(request);
    if (rc == OK)
        rc = task_draw();
    //printf("rc = %d\n", rc);
    if (rc != OK)
        echo_err_message(rc);
}

MainWindow::~MainWindow()
{
    request_t request;
    request.action = QUIT;
    task_manager(request);
    delete scene;
    delete ui;
}

// вызывает менеджер задач для отрисовки объекта
error_t MainWindow::task_draw(void)
{
    auto rect_content = ui->graphicsView->contentsRect();
    ui->graphicsView->scene()->setSceneRect(0, 0, rect_content.width(), rect_content.height());
    request_t request;
    request.action = DRAW;
    request.view = {
        .scene = ui->graphicsView->scene(),
        .width =  rect_content.width(),
        .height =  rect_content.height()
    };
    //printf("act = %d\n", request.action);
    return task_manager(request);
}

void MainWindow::on_Button_move_clicked()
{
    error_t rc = OK;
    request_t request;
    request.action = MOVE;
    request.move.coord_d[0] = ui->entry_dx->value();
    request.move.coord_d[1] = ui->entry_dy->value();
    request.move.coord_d[2] = ui->entry_dz->value();
    rc = task_manager(request);
    if (rc == OK)
        rc = task_draw();
    if (rc != OK)
        echo_err_message(rc);
}

void MainWindow::on_load_data_clicked()
{
    error_t rc = OK;
    request_t request;
    request.action = LOAD;
    request.filename = ui->entry_input_file->text().toStdString().c_str();
    rc = task_manager(request);
    if (rc == OK)
        rc = task_draw();
    if (rc != OK)
        echo_err_message(rc);
}

void MainWindow::on_upload_data_clicked()
{
    error_t rc = OK;
    request_t request;
    request.action = UPLOAD;
    request.filename = ui->entry_output_file->text().toStdString().c_str();
    rc = task_manager(request);
    if (rc == OK)
        rc = task_draw();
    if (rc != OK)
        echo_err_message(rc);
}


void MainWindow::on_Button_scale_clicked()
{
    error_t rc = OK;
    request_t request;
    request.action = SCALE;
    request.scale.coord_k[0] = ui->entry_kx->value();
    request.scale.coord_k[1] = ui->entry_ky->value();
    request.scale.coord_k[2] = ui->entry_kz->value();
    request.scale.central_point[0] = ui->entry_center_scale_x->value();
    request.scale.central_point[1] = ui->entry_center_scale_y->value();
    request.scale.central_point[2] = ui->entry_center_scale_y->value();
    rc = task_manager(request);
    if (rc == OK)
        rc = task_draw();
    if (rc != OK)
        echo_err_message(rc);
}


void MainWindow::on_Button_turn_clicked()
{
    error_t rc = OK;
    request_t request;
    request.action = TURN;
    request.turn.angle = ui->entry_angle_turn->value();
    request.turn.numb_coord = ui->choose_turn_coord->currentIndex();
    request.turn.central_point[0] = ui->entry_center_turn_x->value();
    request.turn.central_point[1] = ui->entry_center_turn_y->value();
    request.turn.central_point[2] = ui->entry_center_turn_y->value();
    rc = task_manager(request);
    if (rc == OK)
        rc = task_draw();
    if (rc != OK)
        echo_err_message(rc);
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

