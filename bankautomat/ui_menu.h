/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(916, 627);
        label = new QLabel(menu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 100, 151, 151));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        btnVaihdaTili = new QPushButton(menu);
        btnVaihdaTili->setObjectName(QStringLiteral("btnVaihdaTili"));
        btnVaihdaTili->setGeometry(QRect(330, 240, 211, 61));
        btnNaytaSaldo = new QPushButton(menu);
        btnNaytaSaldo->setObjectName(QStringLiteral("btnNaytaSaldo"));
        btnNaytaSaldo->setGeometry(QRect(580, 240, 211, 61));
        labelTervetuloa = new QLabel(menu);
        labelTervetuloa->setObjectName(QStringLiteral("labelTervetuloa"));
        labelTervetuloa->setGeometry(QRect(50, 70, 791, 31));
        labelTervetuloa->setFont(font);
        labelTilinro = new QLabel(menu);
        labelTilinro->setObjectName(QStringLiteral("labelTilinro"));
        labelTilinro->setGeometry(QRect(50, 160, 321, 61));
        labelTilityyppi = new QLabel(menu);
        labelTilityyppi->setObjectName(QStringLiteral("labelTilityyppi"));
        labelTilityyppi->setGeometry(QRect(50, 230, 381, 51));
        btnSelaaTapahtumia = new QPushButton(menu);
        btnSelaaTapahtumia->setObjectName(QStringLiteral("btnSelaaTapahtumia"));
        btnSelaaTapahtumia->setGeometry(QRect(320, 360, 211, 61));
        btnNostaRahaa = new QPushButton(menu);
        btnNostaRahaa->setObjectName(QStringLiteral("btnNostaRahaa"));
        btnNostaRahaa->setGeometry(QRect(580, 360, 211, 61));
        btnTalletaRahaa = new QPushButton(menu);
        btnTalletaRahaa->setObjectName(QStringLiteral("btnTalletaRahaa"));
        btnTalletaRahaa->setGeometry(QRect(320, 470, 211, 61));
        btnLogout = new QPushButton(menu);
        btnLogout->setObjectName(QStringLiteral("btnLogout"));
        btnLogout->setGeometry(QRect(30, 320, 201, 121));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("menu", "MENU", Q_NULLPTR));
        btnVaihdaTili->setText(QApplication::translate("menu", "Vaihda tili", Q_NULLPTR));
        btnNaytaSaldo->setText(QApplication::translate("menu", "N\303\244yt\303\244 saldo", Q_NULLPTR));
        labelTervetuloa->setText(QApplication::translate("menu", "\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266", Q_NULLPTR));
        labelTilinro->setText(QApplication::translate("menu", "\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266", Q_NULLPTR));
        labelTilityyppi->setText(QApplication::translate("menu", "\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266\303\266", Q_NULLPTR));
        btnSelaaTapahtumia->setText(QApplication::translate("menu", "Selaa tapahtumia", Q_NULLPTR));
        btnNostaRahaa->setText(QApplication::translate("menu", "Nosta rahaa", Q_NULLPTR));
        btnTalletaRahaa->setText(QApplication::translate("menu", "Talleta rahaa", Q_NULLPTR));
        btnLogout->setText(QApplication::translate("menu", "Kirjaudu ulos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
