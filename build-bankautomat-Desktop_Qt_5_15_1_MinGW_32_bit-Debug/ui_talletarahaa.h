/********************************************************************************
** Form generated from reading UI file 'talletarahaa.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALLETARAHAA_H
#define UI_TALLETARAHAA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_talletaRahaa
{
public:
    QLabel *Otsikko;
    QLineEdit *lineEditRahat;
    QLabel *labelSyotaRahat;
    QPushButton *btnTalleta;
    QLabel *labelIlmoitukset;
    QPushButton *btnTakaisin;

    void setupUi(QDialog *talletaRahaa)
    {
        if (talletaRahaa->objectName().isEmpty())
            talletaRahaa->setObjectName(QString::fromUtf8("talletaRahaa"));
        talletaRahaa->resize(851, 575);
        Otsikko = new QLabel(talletaRahaa);
        Otsikko->setObjectName(QString::fromUtf8("Otsikko"));
        Otsikko->setGeometry(QRect(110, 40, 841, 101));
        QFont font;
        font.setPointSize(12);
        Otsikko->setFont(font);
        lineEditRahat = new QLineEdit(talletaRahaa);
        lineEditRahat->setObjectName(QString::fromUtf8("lineEditRahat"));
        lineEditRahat->setGeometry(QRect(60, 210, 291, 81));
        lineEditRahat->setFont(font);
        lineEditRahat->setStyleSheet(QString::fromUtf8(""));
        lineEditRahat->setAlignment(Qt::AlignCenter);
        labelSyotaRahat = new QLabel(talletaRahaa);
        labelSyotaRahat->setObjectName(QString::fromUtf8("labelSyotaRahat"));
        labelSyotaRahat->setGeometry(QRect(80, 170, 291, 31));
        btnTalleta = new QPushButton(talletaRahaa);
        btnTalleta->setObjectName(QString::fromUtf8("btnTalleta"));
        btnTalleta->setGeometry(QRect(80, 320, 241, 81));
        labelIlmoitukset = new QLabel(talletaRahaa);
        labelIlmoitukset->setObjectName(QString::fromUtf8("labelIlmoitukset"));
        labelIlmoitukset->setGeometry(QRect(390, 210, 441, 91));
        labelIlmoitukset->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        btnTakaisin = new QPushButton(talletaRahaa);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(440, 320, 161, 81));

        retranslateUi(talletaRahaa);

        QMetaObject::connectSlotsByName(talletaRahaa);
    } // setupUi

    void retranslateUi(QDialog *talletaRahaa)
    {
        talletaRahaa->setWindowTitle(QCoreApplication::translate("talletaRahaa", "Dialog", nullptr));
        Otsikko->setText(QCoreApplication::translate("talletaRahaa", "PANOAUTOMAATTI,  RAHAN TALLETUS", nullptr));
        labelSyotaRahat->setText(QCoreApplication::translate("talletaRahaa", "Sy\303\266t\303\244 talletettavat rahat:", nullptr));
        btnTalleta->setText(QCoreApplication::translate("talletaRahaa", "Talleta rahat tilille", nullptr));
        labelIlmoitukset->setText(QString());
        btnTakaisin->setText(QCoreApplication::translate("talletaRahaa", "Takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class talletaRahaa: public Ui_talletaRahaa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALLETARAHAA_H
