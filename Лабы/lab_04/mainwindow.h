#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "LiftSystem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void clientCallLift(int floor, int typeButton);

private slots:
    void on_CabinButtonFloor1_lift1_clicked();

    void on_CabinButtonFloor2_lift1_clicked();

    void on_CabinButtonFloor3_lift1_clicked();

    void on_CabinButtonFloor4_lift1_clicked();

    void on_CabinButtonFloor5_lift1_clicked();

    void on_CabinButtonFloor6_lift1_clicked();

    void on_CabinButtonFloor7_lift1_clicked();

    void on_CabinButtonFloor8_lift1_clicked();

    void on_CabinButtonFloor9_lift1_clicked();

    void on_CabinButtonFloor10_lift1_clicked();

    void on_CabinButtonFloor1_lift2_clicked();

    void on_CabinButtonFloor2_lift2_clicked();

    void on_CabinButtonFloor3_lift2_clicked();

    void on_CabinButtonFloor4_lift2_clicked();

    void on_CabinButtonFloor5_lift2_clicked();

    void on_CabinButtonFloor6_lift2_clicked();

    void on_CabinButtonFloor7_lift2_clicked();

    void on_CabinButtonFloor8_lift2_clicked();

    void on_CabinButtonFloor9_lift2_clicked();

    void on_CabinButtonFloor10_lift2_clicked();

    void on_FloorButton1_clicked();

    void on_FloorButton2_clicked();

    void on_FloorButton3_clicked();

    void on_FloorButton4_clicked();

    void on_FloorButton5_clicked();

    void on_FloorButton6_clicked();

    void on_FloorButton7_clicked();

    void on_FloorButton8_clicked();

    void on_FloorButton9_clicked();

    void on_FloorButton10_clicked();

private:
    Ui::MainWindow *ui;
    LiftSystem lift;
};

#endif // MAINWINDOW_H
