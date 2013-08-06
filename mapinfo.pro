#-------------------------------------------------
#
# Project created by QtCreator 2013-08-06T18:02:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mapinfo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapsloader.cpp \
    maps.cpp \
    mapitem.cpp

HEADERS  += mainwindow.h \
    mapsloader.h \
    maps.h \
    mapitem.h

FORMS    += mainwindow.ui
