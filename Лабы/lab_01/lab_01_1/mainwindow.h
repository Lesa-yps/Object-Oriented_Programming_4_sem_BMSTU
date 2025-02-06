#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ui_mainwindow.h"
#include "struct_actions.h"
#include "Graph_view.h"
#include "const_struct.h"
#include "err_message.h"
#include "task_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_load_data_clicked();

    void on_Button_move_clicked();

    void on_upload_data_clicked();

    void on_Button_scale_clicked();

    void on_Button_turn_clicked();

    void on_menu_author_triggered();

    void on_menu_task_triggered();

    error_t task_draw();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
