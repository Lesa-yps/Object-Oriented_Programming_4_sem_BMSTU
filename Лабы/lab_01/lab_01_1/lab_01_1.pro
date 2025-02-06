QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brain.cpp \
    err_message.cpp \
    init_objt.cpp \
    main.cpp \
    mainwindow.cpp \
    redraw_obj.cpp \
    task_manager.cpp \
    work_with_file.cpp

HEADERS += \
    Graph_view.h \
    brain.h \
    const_struct.h \
    err_message.h \
    init_obj.h \
    mainwindow.h \
    redraw_obj.h \
    struct_actions.h \
    task_manager.h \
    work_with_file.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/cube.txt
