#-------------------------------------------------
#
# Project created by QtCreator 2021-12-02T13:38:15
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bankautomat_crud
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
    tunnuskysely.cpp \
    nayta_asiakkaan_tiedot.cpp \
    nayta_tilin_tiedot.cpp \
    nayta_kortin_tiedot.cpp \
    lisaa_uusi_asiakas.cpp \
    lisaa_uusi_tili.cpp \
    lisaa_uusi_kortti.cpp \
    pankkitilinyhdistaminenasiakastiliin.cpp \
    paivita_asiakkaan_tietoja.cpp \
    paivita_kortin_tietoja.cpp \
    paivita_tilin_tietoja.cpp \
    poista_asiakas.cpp \
    poista_tili.cpp \
    poista_kortti.cpp \
    tilitapahtumien_tulostus.cpp \
    poista_asiakas_pankkitili_yhteys.cpp \
    asiakas_pankkitili_yhteys.cpp

HEADERS += \
        mainwindow.h \
    tunnuskysely.h \
    nayta_asiakkaan_tiedot.h \
    nayta_tilin_tiedot.h \
    nayta_kortin_tiedot.h \
    lisaa_uusi_asiakas.h \
    lisaa_uusi_tili.h \
    lisaa_uusi_kortti.h \
    pankkitilinyhdistaminenasiakastiliin.h \
    paivita_asiakkaan_tietoja.h \
    paivita_kortin_tietoja.h \
    paivita_tilin_tietoja.h \
    poista_asiakas.h \
    poista_tili.h \
    poista_kortti.h \
    tilitapahtumien_tulostus.h \
    poista_asiakas_pankkitili_yhteys.h \
    asiakas_pankkitili_yhteys.h

FORMS += \
        mainwindow.ui \
    tunnuskysely.ui \
    nayta_asiakkaan_tiedot.ui \
    nayta_tilin_tiedot.ui \
    nayta_kortin_tiedot.ui \
    lisaa_uusi_asiakas.ui \
    lisaa_uusi_tili.ui \
    lisaa_uusi_kortti.ui \
    pankkitilinyhdistaminenasiakastiliin.ui \
    paivita_asiakkaan_tietoja.ui \
    paivita_kortin_tietoja.ui \
    paivita_tilin_tietoja.ui \
    poista_asiakas.ui \
    poista_tili.ui \
    poista_kortti.ui \
    tilitapahtumien_tulostus.ui \
    poista_asiakas_pankkitili_yhteys.ui \
    asiakas_pankkitili_yhteys.ui
