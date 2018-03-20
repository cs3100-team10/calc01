#-------------------------------------------------
#
# Project created by QtCreator 2018-02-21T12:25:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = T10Calculator
TEMPLATE = app

INCLUDEPATH += $$PWD/vendor \
    $$PWD/src

SOURCES += src/main.cpp \
    src/exprtk_parse.cpp \
    src/mainwindow.cpp \
    src/scientificwindow.cpp \
    src/memStorage.cpp \
    src/helpdialogbasic.cpp \
    src/helpdialogsci.cpp

HEADERS  += src/mainwindow.h \
    src/exprtk_parse.h \
    src/scientificwindow.h \
    src/memStorage.h \
    src/helpdialogbasic.h \
    src/helpdialogsci.h

FORMS    += src/mainwindow.ui \
    src/scientificwindow.ui \
    src/helpdialogbasic.ui \
    src/helpdialogsci.ui

DISTFILES +=

QMAKE_CXXFLAGS += -Wa,-mbig-obj
