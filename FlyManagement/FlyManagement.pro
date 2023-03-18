#-------------------------------------------------
#
# Project created by QtCreator 2022-05-03T09:12:24
#
#-------------------------------------------------

QT       += core gui
QT += charts
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++14
TARGET = FlyManagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        ryanair.cpp \
        viaggio.cpp \
    airpartner.cpp \
    vettore.cpp \
    locazione.cpp \
    createviaggio.cpp \
    model.cpp \
    mainwindow.cpp \
    main.cpp \
    tableRya.cpp \
    controller.cpp \
    rowviaggio.cpp \
    graficobar.cpp \
    graphprincipale.cpp \
    graficoline.cpp \
    tabprincipale.cpp \
    graficopie.cpp \
    readwritexml.cpp

HEADERS += \
        ryanair.h \
        viaggio.h \
    airpartner.h \
    vettore.h \
    locazione.h \
    createviaggio.h \
    model.h \
    mainwindow.h \
    main.h \
    tableRya.h \
    controller.h \
    rowviaggio.h \
    graficobar.h \
    graphprincipale.h \
    graficoline.h \
    tabprincipale.h \
    graficopie.h \
    readwritexml.h

RESOURCES += \
    images.qrc
