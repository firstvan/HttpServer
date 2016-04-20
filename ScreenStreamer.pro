#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T12:49:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScreenStreamer
TEMPLATE = app

CONFIG += c++14

SOURCES += src/htmlparser.cpp \
    src/htmlroute.cpp \
    src/htmlserve.cpp \
    src/httpserver.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS  += include/mainwindow.h \
    include/httpserver.h \
    include/httpdefine.h \
    include/htmlserve.h \
    include/htmlroute.h \
    include/htmlparser.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
