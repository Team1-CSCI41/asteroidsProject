#-------------------------------------------------
#
# Project created by QtCreator 2014-04-02T12:14:53
#
#-------------------------------------------------

QT       += core gui

TARGET = Asteroids
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    station.cpp \
    asteroid.cpp \
    bullet.cpp \
    keypress.cpp

HEADERS  += mainwindow.h \
    scene.h \
    commandstationadd.h \
    commandstationmove.h \
    commandstationdelete.h \
    station.h \
    asteroid.h \
    bullet.h \
    commandbulletadd.h \
    commandbulletdelete.h \
    commandbulletmove.h \
    commandasteroidadd.h \
    commandasteroiddelete.h \
    commandasteroidmove.h \
    keypress.h

FORMS    += mainwindow.ui
