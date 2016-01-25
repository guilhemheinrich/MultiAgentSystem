QT += core

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11
INSTALLS += target
TARGET = MultiAgentSystem
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    openglwindow.cpp \
    gamewindow.cpp \
    tools.cpp \
    abstractagent.cpp \
    overmind.cpp

HEADERS += \
    openglwindow.h \
    gamewindow.h \
    tools.h \
    cpplinq.hpp \
    cpplinq.hpp \
    abstractagent.h \
    overmind.h
RESOURCES += gestionnaire.qrc

DISTFILES += \
    player.fsh \
    player.vsh
