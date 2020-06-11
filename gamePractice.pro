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
    Game.cpp \
    Player.cpp \
    Health.cpp \
    Score.cpp \
    Button.cpp \
    Limiter.cpp \
    Enemy.cpp \
    Bullet.cpp

HEADERS  += \
    Player.h \
    Game.h \
    Enemy.h \
    Health.h \
    Score.h \
    Button.h \
    Limiter.h \
    Bullet.h

FORMS    += mainwindow.ui

DISTFILES += \
    09 Dance Of The Resplendent Spirits.m4a
