#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T11:29:22
#
#-------------------------------------------------
QT       += core sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = week3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    models/computer.cpp \
    models/scientist.cpp \
    repositories/computerrepository.cpp \
    repositories/linkrepository.cpp \
    repositories/scientistrepository.cpp \
    services/computerservice.cpp \
    services/linkservice.cpp \
    services/scientistservice.cpp \
    utilities/utils.cpp \
    addnewscientistdialog.cpp \
    adnewcomputerdialog.cpp \
    editscientistdialog.cpp \
    editcomputerdialog.cpp \
    addnewrelationdialog.cpp

HEADERS  += mainwindow.h \
    models/computer.h \
    models/scientist.h \
    repositories/computerrepository.h \
    repositories/linkrepository.h \
    repositories/scientistrepository.h \
    services/computerservice.h \
    services/linkservice.h \
    services/scientistservice.h \
    utilities/constants.h \
    utilities/utils.h \
    addnewscientistdialog.h \
    adnewcomputerdialog.h \
    editscientistdialog.h \
    editcomputerdialog.h \
    addnewrelationdialog.h

FORMS    += mainwindow.ui \
    addnewscientistdialog.ui \
    adnewcomputerdialog.ui \
    editscientistdialog.ui \
    editcomputerdialog.ui \
    addnewrelationdialog.ui
