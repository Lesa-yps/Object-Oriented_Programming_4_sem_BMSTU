QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    my_base_exception.h \
    my_base_iterator.h \
    my_base_iterator.hpp \
    my_base_vector.h \
    my_base_vector.hpp \
    my_citerator.h \
    my_citerator.hpp \
    my_concepts.hpp \
    my_exception.h \
    my_iterator.h \
    my_iterator.hpp \
    my_vector.h \
    my_vector.hpp
