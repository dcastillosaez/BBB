QT += core
QT -= gui

TARGET = test_servo1
CONFIG += console
CONFIG -= app_bundle
CONFIG +=c++11
TEMPLATE = app

#Configuramos en que Path se va a obtener el ejecutable y todos los binarios

_DEBUG_RELEASE=unknown
CONFIG(debug, debug|release) {
    _DEBUG_RELEASE = debug
}
CONFIG(release, debug|release) {
    _DEBUG_RELEASE = release
}
DESTDIR = $$(HOME)/BBB/build/$$_DEBUG_RELEASE

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc
UI_DIR = $$DESTDIR/.ui

#Incluimos los Paths necesarios del Proyecto

INCLUDEPATH+= \
        ../../include

SOURCES += main.cpp \
    ../../include/GPIOUniv.cpp \
    ../../include/PWMuniv.cpp \
    ../../include/util.cpp \
    ServoManager.cpp

HEADERS += \
    ../../include/GPIOUniv.h \
    ../../include/PWMuniv.h \
    ../../include/util.h \
    ../../include/Structs.h \
    ServoManager.h

