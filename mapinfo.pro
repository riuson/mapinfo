#-------------------------------------------------
#
# Project created by QtCreator 2013-08-06T18:02:31
#
#-------------------------------------------------

OBJECTS_DIR         = .obj
MOC_DIR             = .moc
UI_DIR              = .uic

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mapinfo
TEMPLATE = app

unix:DESTDIR        = ./_linux
win32:DESTDIR       = ./_windows

CONFIG(debug, debug|release) {
    DESTDIR         = $$DESTDIR/debug
    DEFINES        += DEBUG_VERSION
    QMAKE_LIBDIR   += $$DESTDIR
} else {
    DESTDIR         = $$DESTDIR/release
    QMAKE_LIBDIR   += $$DESTDIR
}

SOURCES += main.cpp\
        mainwindow.cpp \
    mapsloader.cpp \
    maps.cpp \
    mapitem.cpp \
    mapscontroller.cpp \
    scaledlabel.cpp

HEADERS  += mainwindow.h \
    mapsloader.h \
    maps.h \
    mapitem.h \
    mapscontroller.h \
    scaledlabel.h

FORMS    += mainwindow.ui
