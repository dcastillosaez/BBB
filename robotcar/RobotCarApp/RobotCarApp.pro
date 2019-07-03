QT += core network
QT -= gui
#Nombre del archivo ejecutable
TARGET = robotcarapp
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
#Directorio donde se ubica el ejecutable
DESTDIR = $$(REPO)/build/$$_DEBUG_RELEASE

OBJECTS_DIR     = $$DESTDIR/.obj
MOC_DIR         = $$DESTDIR/.moc
RCC_DIR         = $$DESTDIR/.rcc
UI_DIR          = $$DESTDIR/.ui

INCLUDEPATH+= \
        ../../include

SOURCES += main.cpp \
    ../../include/GPIOUniv.cpp \
    ../../include/PWMuniv.cpp \
    ../../include/util.cpp \
    genericComms.cpp \
    genericSocket.cpp \
    DCMotorManager.cpp \
    ServoManager.cpp \
    UltraSoundManager.cpp


HEADERS += \
    ../../include/GPIOUniv.h \
    ../../include/PWMuniv.h \
    ../../include/util.h \
    ../../include/Structs.h \
    genericComms.h \
    genericSocket.h \
    DCMotorManager.h \
    ServoManager.h \
    UltraSoundManager.h


