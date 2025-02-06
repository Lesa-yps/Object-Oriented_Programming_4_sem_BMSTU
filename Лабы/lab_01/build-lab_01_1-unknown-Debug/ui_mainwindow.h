/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Button_scale;
    QGraphicsView *graphicsView;
    QPushButton *Button_move;
    QPushButton *Button_turn;
    QLineEdit *x_m;
    QLineEdit *y_m;
    QLineEdit *ky;
    QLineEdit *kx;
    QLineEdit *dy;
    QLineEdit *dx;
    QLineEdit *y_t;
    QLineEdit *x_t;
    QLineEdit *angle_turn;
    QLineEdit *input_file;
    QLineEdit *output_file;
    QLabel *label;
    QLabel *label_2;
    QPushButton *load_data;
    QPushButton *upload_data;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Button_scale = new QPushButton(centralwidget);
        Button_scale->setObjectName(QString::fromUtf8("Button_scale"));
        Button_scale->setGeometry(QRect(450, 100, 121, 31));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 421, 451));
        Button_move = new QPushButton(centralwidget);
        Button_move->setObjectName(QString::fromUtf8("Button_move"));
        Button_move->setGeometry(QRect(450, 194, 121, 31));
        Button_turn = new QPushButton(centralwidget);
        Button_turn->setObjectName(QString::fromUtf8("Button_turn"));
        Button_turn->setGeometry(QRect(450, 310, 121, 31));
        x_m = new QLineEdit(centralwidget);
        x_m->setObjectName(QString::fromUtf8("x_m"));
        x_m->setGeometry(QRect(510, 20, 113, 23));
        y_m = new QLineEdit(centralwidget);
        y_m->setObjectName(QString::fromUtf8("y_m"));
        y_m->setGeometry(QRect(660, 20, 113, 23));
        ky = new QLineEdit(centralwidget);
        ky->setObjectName(QString::fromUtf8("ky"));
        ky->setGeometry(QRect(660, 70, 113, 23));
        kx = new QLineEdit(centralwidget);
        kx->setObjectName(QString::fromUtf8("kx"));
        kx->setGeometry(QRect(510, 70, 113, 23));
        dy = new QLineEdit(centralwidget);
        dy->setObjectName(QString::fromUtf8("dy"));
        dy->setGeometry(QRect(660, 160, 113, 23));
        dx = new QLineEdit(centralwidget);
        dx->setObjectName(QString::fromUtf8("dx"));
        dx->setGeometry(QRect(510, 160, 113, 23));
        y_t = new QLineEdit(centralwidget);
        y_t->setObjectName(QString::fromUtf8("y_t"));
        y_t->setGeometry(QRect(660, 250, 113, 23));
        x_t = new QLineEdit(centralwidget);
        x_t->setObjectName(QString::fromUtf8("x_t"));
        x_t->setGeometry(QRect(510, 250, 113, 23));
        angle_turn = new QLineEdit(centralwidget);
        angle_turn->setObjectName(QString::fromUtf8("angle_turn"));
        angle_turn->setGeometry(QRect(550, 280, 221, 23));
        input_file = new QLineEdit(centralwidget);
        input_file->setObjectName(QString::fromUtf8("input_file"));
        input_file->setGeometry(QRect(560, 360, 221, 21));
        output_file = new QLineEdit(centralwidget);
        output_file->setObjectName(QString::fromUtf8("output_file"));
        output_file->setGeometry(QRect(560, 390, 221, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(450, 360, 81, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 390, 81, 16));
        load_data = new QPushButton(centralwidget);
        load_data->setObjectName(QString::fromUtf8("load_data"));
        load_data->setGeometry(QRect(450, 430, 161, 31));
        upload_data = new QPushButton(centralwidget);
        upload_data->setObjectName(QString::fromUtf8("upload_data"));
        upload_data->setGeometry(QRect(630, 430, 151, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(440, 0, 241, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 50, 201, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(440, 140, 201, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 230, 201, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(440, 280, 201, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(480, 20, 21, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(640, 20, 20, 21));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(480, 250, 21, 21));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(640, 250, 20, 21));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(480, 70, 21, 21));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(640, 70, 21, 21));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(480, 160, 21, 21));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(640, 160, 21, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Button_scale->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        Button_move->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        Button_turn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\262\320\262\320\276\320\264\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\262\321\213\320\262\320\276\320\264\320\260", nullptr));
        load_data->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        upload_data->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\265\321\200\320\265\320\275\320\276\321\201\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\321\203\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "dy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
