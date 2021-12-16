/********************************************************************************
** Form generated from reading UI file 'nosto.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOSTO_H
#define UI_NOSTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_nosto
{
public:
    QPushButton *btnTakaisin;
    QLineEdit *lineEditMuuSumma;
    QPushButton *btn100;
    QLabel *labelOtsikko;
    QPushButton *btn20;
    QPushButton *btnOtaRahat;
    QPushButton *btn200;
    QPushButton *btnMuu;
    QPushButton *btn500;
    QPushButton *btn40;
    QPushButton *btn60;
    QLabel *labelMuuSumma;

    void setupUi(QDialog *nosto)
    {
        if (nosto->objectName().isEmpty())
            nosto->setObjectName(QString::fromUtf8("nosto"));
        nosto->resize(1050, 626);
        btnTakaisin = new QPushButton(nosto);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(620, 420, 151, 71));
        lineEditMuuSumma = new QLineEdit(nosto);
        lineEditMuuSumma->setObjectName(QString::fromUtf8("lineEditMuuSumma"));
        lineEditMuuSumma->setGeometry(QRect(290, 280, 261, 61));
        lineEditMuuSumma->setAlignment(Qt::AlignCenter);
        btn100 = new QPushButton(nosto);
        btn100->setObjectName(QString::fromUtf8("btn100"));
        btn100->setGeometry(QRect(80, 420, 151, 71));
        labelOtsikko = new QLabel(nosto);
        labelOtsikko->setObjectName(QString::fromUtf8("labelOtsikko"));
        labelOtsikko->setGeometry(QRect(140, 100, 531, 51));
        labelOtsikko->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft Sans Serif\";\n"
"color: rgb(0, 0, 0);\n"
""));
        btn20 = new QPushButton(nosto);
        btn20->setObjectName(QString::fromUtf8("btn20"));
        btn20->setGeometry(QRect(80, 180, 151, 71));
        btnOtaRahat = new QPushButton(nosto);
        btnOtaRahat->setObjectName(QString::fromUtf8("btnOtaRahat"));
        btnOtaRahat->setGeometry(QRect(250, 380, 351, 131));
        btnOtaRahat->setStyleSheet(QString::fromUtf8("border-image: url(:/rahat.png);\n"
"font: 10pt \"Lucida Sans\";\n"
"color: rgb(0, 0, 0);"));
        btn200 = new QPushButton(nosto);
        btn200->setObjectName(QString::fromUtf8("btn200"));
        btn200->setGeometry(QRect(620, 180, 151, 71));
        btnMuu = new QPushButton(nosto);
        btnMuu->setObjectName(QString::fromUtf8("btnMuu"));
        btnMuu->setGeometry(QRect(620, 340, 151, 71));
        btn500 = new QPushButton(nosto);
        btn500->setObjectName(QString::fromUtf8("btn500"));
        btn500->setGeometry(QRect(620, 260, 151, 71));
        btn40 = new QPushButton(nosto);
        btn40->setObjectName(QString::fromUtf8("btn40"));
        btn40->setGeometry(QRect(80, 260, 151, 71));
        btn60 = new QPushButton(nosto);
        btn60->setObjectName(QString::fromUtf8("btn60"));
        btn60->setGeometry(QRect(80, 340, 151, 71));
        labelMuuSumma = new QLabel(nosto);
        labelMuuSumma->setObjectName(QString::fromUtf8("labelMuuSumma"));
        labelMuuSumma->setGeometry(QRect(250, 160, 341, 101));

        retranslateUi(nosto);

        QMetaObject::connectSlotsByName(nosto);
    } // setupUi

    void retranslateUi(QDialog *nosto)
    {
        nosto->setWindowTitle(QCoreApplication::translate("nosto", "Dialog", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("nosto", "Takaisin", nullptr));
        btn100->setText(QCoreApplication::translate("nosto", "100", nullptr));
        labelOtsikko->setText(QCoreApplication::translate("nosto", "	Paljonkos aattelit nostaa?", nullptr));
        btn20->setText(QCoreApplication::translate("nosto", "20", nullptr));
        btnOtaRahat->setText(QCoreApplication::translate("nosto", "OTA RAHAT", nullptr));
        btn200->setText(QCoreApplication::translate("nosto", "200", nullptr));
        btnMuu->setText(QCoreApplication::translate("nosto", "Muu summa", nullptr));
        btn500->setText(QCoreApplication::translate("nosto", "500", nullptr));
        btn40->setText(QCoreApplication::translate("nosto", "40", nullptr));
        btn60->setText(QCoreApplication::translate("nosto", "60", nullptr));
        labelMuuSumma->setText(QCoreApplication::translate("nosto", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nosto: public Ui_nosto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOSTO_H
