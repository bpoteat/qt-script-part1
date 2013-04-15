#-------------------------------------------------
#
# Project created by QtCreator 2013-04-15T08:09:24
#
#-------------------------------------------------

QT       += core gui script scripttools uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomApp
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

RESOURCES +=

LIBS += -lQtUiTools
