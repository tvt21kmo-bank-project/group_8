#-------------------------------------------------
#
# Project created by QtCreator 2021-11-21T17:56:08
#
#-------------------------------------------------

QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bankautomat
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
    login.cpp \
    menu.cpp \
    vaihdatili.cpp \
    nostarahaa.cpp \
    naytatapahtumia.cpp \
    saldo.cpp \
    talletarahaa.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    menu.h \
    vaihdatili.h \
    nostarahaa.h \
    naytatapahtumia.h \
    saldo.h \
    talletarahaa.h

FORMS += \
        mainwindow.ui \
    nappiversio.ui \
    menu.ui \
    vaihdatili.ui \
    login.ui \
    login.ui \
    nostarahaa.ui \
    naytatapahtumia.ui \
    saldo.ui \
    talletarahaa.ui
RESOURCES = images/resources.qrc
