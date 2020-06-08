#-------------------------------------------------
#
# Project created by QtCreator 2016-12-29T14:45:02
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gamePractice
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Game.cpp \
    Player.cpp \
    Enemy.cpp \
    Health.cpp \
    Score.cpp \
    Button.cpp \
    Limiter.cpp

HEADERS  += \
    Bullet.h \
    Player.h \
    Game.h \
    Enemy.h \
    Health.h \
    Score.h \
    Button.h \
    Limiter.h

FORMS    += mainwindow.ui

DISTFILES += \
    09 Dance Of The Resplendent Spirits.m4a
