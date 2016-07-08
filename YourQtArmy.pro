#-------------------------------------------------
#
# Project created by QtCreator 2015-12-16T16:29:49
#
#-------------------------------------------------

QT       += core gui\
      xml\

CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YourQtArmy
TEMPLATE = app


SOURCES += main.cpp\
    army.cpp \
    unit.cpp \
    player.cpp \
    user.cpp \
    soldier.cpp \
    freeplayer.cpp \
    premiumplayer.cpp \
    marketlist.cpp \
    battlemanager.cpp \
    appmanager.cpp \
    loginwindow.cpp \
    userwindow.cpp \
    veichle.cpp

HEADERS  += \
    army.h \
    unit.h \
    player.h \
    user.h \
    soldier.h \
    freeplayer.h \
    premiumplayer.h \
    marketlist.h \
    battlemanager.h \
    appmanager.h \
    loginwindow.h \
    userwindow.h \
    veichle.h


RESOURCES += \
    risorse.qrc
