QT += core

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11
INSTALLS += target
TARGET = MultiAgentSystem
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    openglwindow.cpp \
    gamewindow.cpp

HEADERS += \
    openglwindow.h \
    gamewindow.h \
    cpplinq.hpp

