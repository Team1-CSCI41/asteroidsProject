#-------------------------------------------------
#
# Project created by QtCreator 2014-03-26T12:04:11
#
#-------------------------------------------------

QT       += core gui

TARGET = Qsimulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    station.cpp

HEADERS  += mainwindow.h \
    scene.h \
    station.h \
    commandstationadd.h \
    commandstationmove.h \
    commandstationdelete.h

OTHER_FILES += \
    Ship.qml
