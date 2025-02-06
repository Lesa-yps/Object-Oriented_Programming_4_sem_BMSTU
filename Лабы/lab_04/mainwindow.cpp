#include "mainwindow.h"

#include <QDebug>

#include "ui_mainwindow.h"
#include "const.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    qDebug("Лифт на %d этаже, двери закрыты.\nЖдём команды, капитан!\n", START_FLOOR);
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(clientCallLift(int, int)), &lift, SLOT(call(int, int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CabinButtonFloor1_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 1 в панели лифта №1.");
    clientCallLift(1, CABINE1);
}

void MainWindow::on_CabinButtonFloor2_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 2 в панели лифта №1.");
    clientCallLift(2, CABINE1);
}

void MainWindow::on_CabinButtonFloor3_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 3 в панели лифта №1.");
    clientCallLift(3, CABINE1);
}

void MainWindow::on_CabinButtonFloor4_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 4 в панели лифта №1.");
    clientCallLift(4, CABINE1);
}

void MainWindow::on_CabinButtonFloor5_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 5 в панели лифта №1.");
    clientCallLift(5, CABINE1);
}

void MainWindow::on_CabinButtonFloor6_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 6 в панели лифта №1.");
    clientCallLift(6, CABINE1);
}

void MainWindow::on_CabinButtonFloor7_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 7 в панели лифта №1.");
    clientCallLift(7, CABINE1);
}

void MainWindow::on_CabinButtonFloor8_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 8 в панели лифта №1.");
    clientCallLift(8, CABINE1);
}

void MainWindow::on_CabinButtonFloor9_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 9 в панели лифта №1.");
    clientCallLift(9, CABINE1);
}

void MainWindow::on_CabinButtonFloor10_lift1_clicked()
{
    qDebug("Была нажата кнопка для этажа 10 в панели лифта №1.");
    clientCallLift(10, CABINE1);
}

void MainWindow::on_CabinButtonFloor1_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 1 в панели лифта №2.");
    clientCallLift(1, CABINE2);
}

void MainWindow::on_CabinButtonFloor2_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 2 в панели лифта №2.");
    clientCallLift(2, CABINE2);
}

void MainWindow::on_CabinButtonFloor3_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 3 в панели лифта №2.");
    clientCallLift(3, CABINE2);
}

void MainWindow::on_CabinButtonFloor4_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 4 в панели лифта №2.");
    clientCallLift(4, CABINE2);
}

void MainWindow::on_CabinButtonFloor5_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 5 в панели лифта №2.");
    clientCallLift(5, CABINE2);
}

void MainWindow::on_CabinButtonFloor6_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 6 в панели лифта №2.");
    clientCallLift(6, CABINE2);
}

void MainWindow::on_CabinButtonFloor7_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 7 в панели лифта №2.");
    clientCallLift(7, CABINE2);
}

void MainWindow::on_CabinButtonFloor8_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 8 в панели лифта №2.");
    clientCallLift(8, CABINE2);
}

void MainWindow::on_CabinButtonFloor9_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 9 в панели лифта №2.");
    clientCallLift(9, CABINE2);
}

void MainWindow::on_CabinButtonFloor10_lift2_clicked()
{
    qDebug("Была нажата кнопка для этажа 10 в панели лифта №2.");
    clientCallLift(10, CABINE2);
}

void MainWindow::on_FloorButton1_clicked()
{
    qDebug() << "Лифт был вызван на этаже №1.";
    clientCallLift(1, FLOOR);
}

void MainWindow::on_FloorButton2_clicked()
{
    qDebug() << "Лифт был вызван на этаже №2.";
    clientCallLift(2, FLOOR);
}

void MainWindow::on_FloorButton3_clicked()
{
    qDebug() << "Лифт был вызван на этаже №3.";
    clientCallLift(3, FLOOR);
}

void MainWindow::on_FloorButton4_clicked()
{
    qDebug() << "Лифт был вызван на этаже №4.";
    clientCallLift(4, FLOOR);
}

void MainWindow::on_FloorButton5_clicked()
{
    qDebug() << "Лифт был вызван на этаже №5.";
    clientCallLift(5, FLOOR);
}

void MainWindow::on_FloorButton6_clicked()
{
    qDebug() << "Лифт был вызван на этаже №6.";
    clientCallLift(6, FLOOR);
}

void MainWindow::on_FloorButton7_clicked()
{
    qDebug() << "Лифт был вызван на этаже №7.";
    clientCallLift(7, FLOOR);
}

void MainWindow::on_FloorButton8_clicked()
{
    qDebug() << "Лифт был вызван на этаже №8.";
    clientCallLift(8, FLOOR);
}

void MainWindow::on_FloorButton9_clicked()
{
    qDebug() << "Лифт был вызван на этаже №9.";
    clientCallLift(9, FLOOR);
}

void MainWindow::on_FloorButton10_clicked()
{
    qDebug() << "Лифт был вызван на этаже №10.";
    clientCallLift(10, FLOOR);
}
