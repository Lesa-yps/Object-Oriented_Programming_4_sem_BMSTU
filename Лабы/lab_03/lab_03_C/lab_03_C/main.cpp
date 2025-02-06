#include <QApplication>

#include "mainwindow.h"

auto main(int argc, char *argv[]) -> int
{
    QApplication a(argc, argv);

    MainWindow w;
    w.showMaximized();

    return a.exec();
}
