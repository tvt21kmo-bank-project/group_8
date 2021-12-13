/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QLabel *label;
    QPushButton *btnVaihdaTili;
    QPushButton *btnNaytaSaldo;
    QLabel *labelTervetuloa;
    QLabel *labelTilinro;
    QLabel *labelTilityyppi;
    QPushButton *btnSelaaTapahtumia;
    QPushButton *btnNostaRahaa;
    QPushButton *btnTalletaRahaa;
    QPushButton *btnLogout;
    QPushButton *btnTilisiirto;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(916, 627);
        label = new QLabel(menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 100, 151, 151));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        btnVaihdaTili = new QPushButton(menu);
        btnVaihdaTili->setObjectName(QString::fromUtf8("btnVaihdaTili"));
        btnVaihdaTili->setGeometry(QRect(330, 240, 211, 61));
        btnNaytaSaldo = new QPushButton(menu);
        btnNaytaSaldo->setObjectName(QString::fromUtf8("btnNaytaSaldo"));
        btnNaytaSaldo->setGeometry(QRect(580, 240, 211, 61));
        labelTervetuloa = new QLabel(menu);
        labelTervetuloa->setObjectName(QString::fromUtf8("labelTervetuloa"));
        labelTervetuloa->setGeometry(QRect(50, 70, 791, 31));
        labelTervetuloa->setFont(font);
        labelTilinro = new QLabel(menu);
        labelTilinro->setObjectName(QString::fromUtf8("labelTilinro"));
        labelTilinro->setGeometry(QRect(50, 120, 321, 61));
        labelTilityyppi = new QLabel(menu);
        labelTilityyppi->setObjectName(QString::fromUtf8("labelTilityyppi"));
        labelTilityyppi->setGeometry(QRect(50, 170, 381, 51));
        btnSelaaTapahtumia = new QPushButton(menu);
        btnSelaaTapahtumia->setObjectName(QString::fromUtf8("btnSelaaTapahtumia"));
        btnSelaaTapahtumia->setGeometry(QRect(320, 360, 211, 61));
        btnNostaRahaa = new QPushButton(menu);
        btnNostaRahaa->setObjectName(QString::fromUtf8("btnNostaRahaa"));
        btnNostaRahaa->setGeometry(QRect(580, 360, 211, 61));
        btnTalletaRahaa = new QPushButton(menu);
        btnTalletaRahaa->setObjectName(QString::fromUtf8("btnTalletaRahaa"));
        btnTalletaRahaa->setGeometry(QRect(320, 470, 211, 61));
        btnLogout = new QPushButton(menu);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));
        btnLogout->setGeometry(QRect(50, 240, 201, 121));
        btnTilisiirto = new QPushButton(menu);
        btnTilisiirto->setObjectName(QString::fromUtf8("btnTilisiirto"));
        btnTilisiirto->setGeometry(QRect(580, 470, 211, 61));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Form", nullptr));
        label->setText(QCoreApplication::translate("menu", "MENU", nullptr));
        btnVaihdaTili->setText(QCoreApplication::translate("menu", "Vaihda tili", nullptr));
        btnNaytaSaldo->setText(QCoreApplication::translate("menu", "N\303\244yt\303\244 saldo", nullptr));
        labelTervetuloa->setText(QCoreApplication::translate("menu", "\303\266", nullptr));
        labelTilinro->setText(QCoreApplication::translate("menu", "\303\266", nullptr));
        labelTilityyppi->setText(QCoreApplication::translate("menu", "\303\266", nullptr));
        btnSelaaTapahtumia->setText(QCoreApplication::translate("menu", "Selaa tapahtumia", nullptr));
        btnNostaRahaa->setText(QCoreApplication::translate("menu", "Nosta rahaa", nullptr));
        btnTalletaRahaa->setText(QCoreApplication::translate("menu", "Talleta rahaa", nullptr));
        btnLogout->setText(QCoreApplication::translate("menu", "Kirjaudu ulos", nullptr));
        btnTilisiirto->setText(QCoreApplication::translate("menu", "Tilisiirto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
