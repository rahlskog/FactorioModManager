#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T17:12:15
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FactorioModManager
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    mod.cpp \
    modlistmodel.cpp \
    moddependenciesdelegate.cpp \
    modlist.cpp

HEADERS  += mainwindow.h \
    mod.h \
    modlistmodel.h \
    moddependenciesdelegate.h \
    modlist.h

FORMS    += mainwindow.ui

LIBS += -L/usr/local/lib -lPocoZip -lPocoFoundation
