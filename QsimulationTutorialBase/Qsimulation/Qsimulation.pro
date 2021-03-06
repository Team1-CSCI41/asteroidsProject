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
    station.cpp \
    bullet.cpp \
    asteroid.cpp \
    keypress.cpp

HEADERS  += mainwindow.h \
    scene.h \
    station.h \
    commandstationadd.h \
    commandstationmove.h \
    commandstationdelete.h \
    bullet.h \
    asteroid.h \
    keypress.h \
    commandbulletadd.h \
    commandbulletdelete.h \
    commandbulletmove.h \
    commandasteroidadd.h \
    commandasteroiddelete.h \
    commandasteroidmove.h

OTHER_FILES += \
    Ship.qml
