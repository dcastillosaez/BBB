QT += core
QT -= gui

TARGET = RobotCarApp
CONFIG += console
CONFIG -= app_bundle
CONFIG +=c++11
TEMPLATE = app

INCLUDEPATH+= \
        ../../include
SOURCES += main.cpp \
    ../../include/GPIOUniv.cpp \
    ../../include/PWMuniv.cpp \
    ../../include/util.cpp

HEADERS += \
    ../../include/GPIOUniv.h \
    ../../include/PWMuniv.h \
    ../../include/util.h

