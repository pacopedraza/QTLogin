#-------------------------------------------------
#
# Project created by QtCreator 2017-06-10T10:30:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Login
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    randomkey.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    randomkey.h

FORMS    += mainwindow.ui \
    dialog.ui \
    randomkey.ui

RESOURCES += \
    logo.qrc \
    res2.qrc \
    results.qrc \
    results/res2.qrc \
    Res/myres.qrc
