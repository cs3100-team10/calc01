#-------------------------------------------------
#
# Project created by QtCreator 2018-02-21T12:25:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = T10Calculator
TEMPLATE = app

SOURCES += src/main.cpp src/mainwindow.cpp \
    src/scientificwindow.cpp \
    src/memstorage.cpp

HEADERS  += src/mainwindow.h \
    src/scientificwindow.h

FORMS    += src/mainwindow.ui \
    src/scientificwindow.ui

DISTFILES +=
