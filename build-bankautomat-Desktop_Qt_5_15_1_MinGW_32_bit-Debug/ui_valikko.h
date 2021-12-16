/********************************************************************************
** Form generated from reading UI file 'valikko.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALIKKO_H
#define UI_VALIKKO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_valikko
{
public:
    QPushButton *btnVaihdaTili;
    QLabel *labelTilinro;
    QLabel *labelTilityyppi;
    QLabel *label;
    QPushButton *btnLogout;
    QPushButton *btnNostaRahaa;
    QPushButton *btnSelaaTapahtumia;
    QLabel *labelTervetuloa;
    QPushButton *btnTalletaRahaa;
    QPushButton *btnNaytaSaldo;
    QPushButton *btnTilisiirto;

    void setupUi(QDialog *valikko)
    {
        if (valikko->objectName().isEmpty())
            valikko->setObjectName(QString::fromUtf8("valikko"));
        valikko->resize(897, 601);
        btnVaihdaTili = new QPushButton(valikko);
        btnVaihdaTili->setObjectName(QString::fromUtf8("btnVaihdaTili"));
        btnVaihdaTili->setGeometry(QRect(330, 190, 211, 61));
        labelTilinro = new QLabel(valikko);
        labelTilinro->setObjectName(QString::fromUtf8("labelTilinro"));
        labelTilinro->setGeometry(QRect(50, 70, 321, 61));
        labelTilityyppi = new QLabel(valikko);
        labelTilityyppi->setObjectName(QString::fromUtf8("labelTilityyppi"));
        labelTilityyppi->setGeometry(QRect(50, 120, 381, 51));
        label = new QLabel(valikko);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 50, 151, 151));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        btnLogout = new QPushButton(valikko);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));
        btnLogout->setGeometry(QRect(50, 190, 201, 121));
        btnNostaRahaa = new QPushButton(valikko);
        btnNostaRahaa->setObjectName(QString::fromUtf8("btnNostaRahaa"));
        btnNostaRahaa->setGeometry(QRect(580, 310, 211, 61));
        btnSelaaTapahtumia = new QPushButton(valikko);
        btnSelaaTapahtumia->setObjectName(QString::fromUtf8("btnSelaaTapahtumia"));
        btnSelaaTapahtumia->setGeometry(QRect(320, 310, 211, 61));
        labelTervetuloa = new QLabel(valikko);
        labelTervetuloa->setObjectName(QString::fromUtf8("labelTervetuloa"));
        labelTervetuloa->setGeometry(QRect(50, 20, 791, 31));
        labelTervetuloa->setFont(font);
        btnTalletaRahaa = new QPushButton(valikko);
        btnTalletaRahaa->setObjectName(QString::fromUtf8("btnTalletaRahaa"));
        btnTalletaRahaa->setGeometry(QRect(320, 420, 211, 61));
        btnNaytaSaldo = new QPushButton(valikko);
        btnNaytaSaldo->setObjectName(QString::fromUtf8("btnNaytaSaldo"));
        btnNaytaSaldo->setGeometry(QRect(580, 190, 211, 61));
        btnTilisiirto = new QPushButton(valikko);
        btnTilisiirto->setObjectName(QString::fromUtf8("btnTilisiirto"));
        btnTilisiirto->setGeometry(QRect(580, 420, 211, 61));

        retranslateUi(valikko);

        QMetaObject::connectSlotsByName(valikko);
    } // setupUi

    void retranslateUi(QDialog *valikko)
    {
        valikko->setWindowTitle(QCoreApplication::translate("valikko", "Dialog", nullptr));
        btnVaihdaTili->setText(QCoreApplication::translate("valikko", "Vaihda tili", nullptr));
        labelTilinro->setText(QCoreApplication::translate("valikko", "\303\266", nullptr));
        labelTilityyppi->setText(QCoreApplication::translate("valikko", "\303\266", nullptr));
        label->setText(QCoreApplication::translate("valikko", "MENU", nullptr));
        btnLogout->setText(QCoreApplication::translate("valikko", "Kirjaudu ulos", nullptr));
        btnNostaRahaa->setText(QCoreApplication::translate("valikko", "Nosta rahaa", nullptr));
        btnSelaaTapahtumia->setText(QCoreApplication::translate("valikko", "Selaa tapahtumia", nullptr));
        labelTervetuloa->setText(QCoreApplication::translate("valikko", "\303\266", nullptr));
        btnTalletaRahaa->setText(QCoreApplication::translate("valikko", "Talleta rahaa", nullptr));
        btnNaytaSaldo->setText(QCoreApplication::translate("valikko", "N\303\244yt\303\244 saldo", nullptr));
        btnTilisiirto->setText(QCoreApplication::translate("valikko", "Tilisiirto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class valikko: public Ui_valikko {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALIKKO_H
