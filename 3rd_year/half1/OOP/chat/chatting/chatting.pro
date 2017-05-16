#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T15:42:54
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chat.cpp

HEADERS  += mainwindow.h \
    chat.h

FORMS    += mainwindow.ui
QMAKE_CXXFLAGS += -std=c++14
