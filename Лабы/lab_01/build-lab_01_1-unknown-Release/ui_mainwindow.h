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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *menu_author;
    QAction *menu_task;
    QWidget *centralwidget;
    QPushButton *Button_scale;
    QPushButton *Button_move;
    QPushButton *Button_turn;
    QLineEdit *entry_input_file;
    QLineEdit *entry_output_file;
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
    QLabel *label_12;
    QLabel *label_13;
    QGraphicsView *graphicsView;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_20;
    QComboBox *choose_turn_coord;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *entry_dy;
    QDoubleSpinBox *entry_dx;
    QDoubleSpinBox *entry_dz;
    QLabel *label_18;
    QSpinBox *entry_center_turn_z;
    QLabel *label_10;
    QLabel *label_19;
    QLabel *label_11;
    QDoubleSpinBox *entry_angle_turn;
    QSpinBox *entry_center_turn_y;
    QSpinBox *entry_center_turn_x;
    QDoubleSpinBox *entry_kx;
    QDoubleSpinBox *entry_ky;
    QDoubleSpinBox *entry_kz;
    QSpinBox *entry_center_scale_x;
    QSpinBox *entry_center_scale_y;
    QSpinBox *entry_center_scale_z;
    QMenuBar *menubar;
    QMenu *menu_info;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(919, 532);
        menu_author = new QAction(MainWindow);
        menu_author->setObjectName(QString::fromUtf8("menu_author"));
        menu_task = new QAction(MainWindow);
        menu_task->setObjectName(QString::fromUtf8("menu_task"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Button_scale = new QPushButton(centralwidget);
        Button_scale->setObjectName(QString::fromUtf8("Button_scale"));
        Button_scale->setGeometry(QRect(600, 120, 171, 31));
        Button_move = new QPushButton(centralwidget);
        Button_move->setObjectName(QString::fromUtf8("Button_move"));
        Button_move->setGeometry(QRect(600, 214, 171, 31));
        Button_turn = new QPushButton(centralwidget);
        Button_turn->setObjectName(QString::fromUtf8("Button_turn"));
        Button_turn->setGeometry(QRect(600, 330, 171, 31));
        entry_input_file = new QLineEdit(centralwidget);
        entry_input_file->setObjectName(QString::fromUtf8("entry_input_file"));
        entry_input_file->setGeometry(QRect(680, 380, 231, 21));
        entry_output_file = new QLineEdit(centralwidget);
        entry_output_file->setObjectName(QString::fromUtf8("entry_output_file"));
        entry_output_file->setGeometry(QRect(680, 410, 231, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(590, 380, 81, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(590, 410, 81, 16));
        load_data = new QPushButton(centralwidget);
        load_data->setObjectName(QString::fromUtf8("load_data"));
        load_data->setGeometry(QRect(600, 450, 151, 31));
        upload_data = new QPushButton(centralwidget);
        upload_data->setObjectName(QString::fromUtf8("upload_data"));
        upload_data->setGeometry(QRect(770, 450, 141, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(590, 10, 241, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(590, 70, 201, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(590, 160, 201, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(590, 250, 201, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(590, 300, 201, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(630, 40, 21, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(730, 40, 20, 21));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(630, 90, 21, 21));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(730, 90, 21, 21));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 551, 471));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(830, 40, 20, 21));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(830, 90, 21, 21));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(760, 300, 91, 21));
        choose_turn_coord = new QComboBox(centralwidget);
        choose_turn_coord->addItem(QString());
        choose_turn_coord->addItem(QString());
        choose_turn_coord->addItem(QString());
        choose_turn_coord->setObjectName(QString::fromUtf8("choose_turn_coord"));
        choose_turn_coord->setGeometry(QRect(860, 300, 51, 23));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(630, 180, 21, 21));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(730, 180, 21, 21));
        entry_dy = new QDoubleSpinBox(centralwidget);
        entry_dy->setObjectName(QString::fromUtf8("entry_dy"));
        entry_dy->setGeometry(QRect(750, 180, 62, 23));
        entry_dy->setMinimum(-10000.000000000000000);
        entry_dy->setMaximum(10000.000000000000000);
        entry_dy->setSingleStep(0.100000000000000);
        entry_dx = new QDoubleSpinBox(centralwidget);
        entry_dx->setObjectName(QString::fromUtf8("entry_dx"));
        entry_dx->setGeometry(QRect(650, 180, 62, 23));
        entry_dx->setMinimum(-10000.000000000000000);
        entry_dx->setMaximum(10000.000000000000000);
        entry_dx->setSingleStep(0.100000000000000);
        entry_dz = new QDoubleSpinBox(centralwidget);
        entry_dz->setObjectName(QString::fromUtf8("entry_dz"));
        entry_dz->setGeometry(QRect(850, 180, 62, 23));
        entry_dz->setMinimum(-10000.000000000000000);
        entry_dz->setMaximum(10000.000000000000000);
        entry_dz->setSingleStep(0.100000000000000);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(830, 180, 21, 21));
        entry_center_turn_z = new QSpinBox(centralwidget);
        entry_center_turn_z->setObjectName(QString::fromUtf8("entry_center_turn_z"));
        entry_center_turn_z->setGeometry(QRect(850, 270, 61, 23));
        entry_center_turn_z->setMinimum(-10000);
        entry_center_turn_z->setMaximum(10000);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(730, 270, 20, 21));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(830, 270, 20, 21));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(630, 270, 21, 21));
        entry_angle_turn = new QDoubleSpinBox(centralwidget);
        entry_angle_turn->setObjectName(QString::fromUtf8("entry_angle_turn"));
        entry_angle_turn->setGeometry(QRect(690, 300, 62, 23));
        entry_angle_turn->setMinimum(-360.000000000000000);
        entry_angle_turn->setMaximum(360.000000000000000);
        entry_angle_turn->setSingleStep(0.100000000000000);
        entry_center_turn_y = new QSpinBox(centralwidget);
        entry_center_turn_y->setObjectName(QString::fromUtf8("entry_center_turn_y"));
        entry_center_turn_y->setGeometry(QRect(750, 270, 61, 23));
        entry_center_turn_y->setMinimum(-10000);
        entry_center_turn_y->setMaximum(10000);
        entry_center_turn_x = new QSpinBox(centralwidget);
        entry_center_turn_x->setObjectName(QString::fromUtf8("entry_center_turn_x"));
        entry_center_turn_x->setGeometry(QRect(650, 270, 61, 23));
        entry_center_turn_x->setMinimum(-10000);
        entry_center_turn_x->setMaximum(10000);
        entry_kx = new QDoubleSpinBox(centralwidget);
        entry_kx->setObjectName(QString::fromUtf8("entry_kx"));
        entry_kx->setGeometry(QRect(650, 90, 62, 23));
        entry_kx->setMinimum(-10000.000000000000000);
        entry_kx->setMaximum(10000.000000000000000);
        entry_kx->setSingleStep(0.100000000000000);
        entry_ky = new QDoubleSpinBox(centralwidget);
        entry_ky->setObjectName(QString::fromUtf8("entry_ky"));
        entry_ky->setGeometry(QRect(750, 90, 62, 23));
        entry_ky->setMinimum(-10000.000000000000000);
        entry_ky->setMaximum(10000.000000000000000);
        entry_ky->setSingleStep(0.100000000000000);
        entry_kz = new QDoubleSpinBox(centralwidget);
        entry_kz->setObjectName(QString::fromUtf8("entry_kz"));
        entry_kz->setGeometry(QRect(850, 90, 62, 23));
        entry_kz->setMinimum(-10000.000000000000000);
        entry_kz->setMaximum(10000.000000000000000);
        entry_kz->setSingleStep(0.100000000000000);
        entry_center_scale_x = new QSpinBox(centralwidget);
        entry_center_scale_x->setObjectName(QString::fromUtf8("entry_center_scale_x"));
        entry_center_scale_x->setGeometry(QRect(650, 40, 61, 23));
        entry_center_scale_x->setMinimum(-10000);
        entry_center_scale_x->setMaximum(10000);
        entry_center_scale_y = new QSpinBox(centralwidget);
        entry_center_scale_y->setObjectName(QString::fromUtf8("entry_center_scale_y"));
        entry_center_scale_y->setGeometry(QRect(750, 40, 61, 23));
        entry_center_scale_y->setMinimum(-10000);
        entry_center_scale_y->setMaximum(10000);
        entry_center_scale_z = new QSpinBox(centralwidget);
        entry_center_scale_z->setObjectName(QString::fromUtf8("entry_center_scale_z"));
        entry_center_scale_z->setGeometry(QRect(850, 40, 61, 23));
        entry_center_scale_z->setMinimum(-10000);
        entry_center_scale_z->setMaximum(10000);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 919, 23));
        menu_info = new QMenu(menubar);
        menu_info->setObjectName(QString::fromUtf8("menu_info"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_info->menuAction());
        menu_info->addAction(menu_author);
        menu_info->addAction(menu_task);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        menu_author->setText(QCoreApplication::translate("MainWindow", "\320\260\320\262\321\202\320\276\321\200", nullptr));
        menu_task->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
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
        label_12->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\276\321\201\321\214 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", nullptr));
        choose_turn_coord->setItemText(0, QCoreApplication::translate("MainWindow", "X", nullptr));
        choose_turn_coord->setItemText(1, QCoreApplication::translate("MainWindow", "Y", nullptr));
        choose_turn_coord->setItemText(2, QCoreApplication::translate("MainWindow", "Z", nullptr));

        label_14->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "dy", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "dz", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        menu_info->setTitle(QCoreApplication::translate("MainWindow", "\320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
