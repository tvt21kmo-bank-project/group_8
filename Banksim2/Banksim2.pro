#-------------------------------------------------
#
# Project created by QtCreator 2021-11-30T13:23:56
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Banksim2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    creditvaidebit.cpp \
    menu.cpp \
    saldo.cpp \
    tilitapahtumat.cpp \
    nosto.cpp \
    talleta.cpp \
    siirra.cpp \
    vaihda.cpp

HEADERS += \
        mainwindow.h \
    creditvaidebit.h \
    menu.h \
    saldo.h \
    tilitapahtumat.h \
    nosto.h \
    talleta.h \
    siirra.h \
    vaihda.h

FORMS += \
        mainwindow.ui \
    creditvaidebit.ui \
    menu.ui \
    saldo.ui \
    tilitapahtumat.ui \
    nosto.ui \
    talleta.ui \
    siirra.ui \
    vaihda.ui
