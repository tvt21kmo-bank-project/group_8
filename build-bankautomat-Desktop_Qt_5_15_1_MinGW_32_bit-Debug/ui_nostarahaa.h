/********************************************************************************
** Form generated from reading UI file 'nostarahaa.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOSTARAHAA_H
#define UI_NOSTARAHAA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_nostaRahaa
{
public:
    QPushButton *btn20;
    QPushButton *btn40;
    QPushButton *btn60;
    QPushButton *btn100;
    QPushButton *btn200;
    QPushButton *btn500;
    QPushButton *btnMuu;
    QPushButton *btnTakaisin;
    QPushButton *btnOtaRahat;
    QLineEdit *lineEditMuuSumma;
    QLabel *labelMuuSumma;
    QLabel *labelOtsikko;

    void setupUi(QDialog *nostaRahaa)
    {
        if (nostaRahaa->objectName().isEmpty())
            nostaRahaa->setObjectName(QString::fromUtf8("nostaRahaa"));
        nostaRahaa->resize(852, 591);
        btn20 = new QPushButton(nostaRahaa);
        btn20->setObjectName(QString::fromUtf8("btn20"));
        btn20->setGeometry(QRect(70, 140, 151, 71));
        btn40 = new QPushButton(nostaRahaa);
        btn40->setObjectName(QString::fromUtf8("btn40"));
        btn40->setGeometry(QRect(70, 220, 151, 71));
        btn60 = new QPushButton(nostaRahaa);
        btn60->setObjectName(QString::fromUtf8("btn60"));
        btn60->setGeometry(QRect(70, 300, 151, 71));
        btn100 = new QPushButton(nostaRahaa);
        btn100->setObjectName(QString::fromUtf8("btn100"));
        btn100->setGeometry(QRect(70, 380, 151, 71));
        btn200 = new QPushButton(nostaRahaa);
        btn200->setObjectName(QString::fromUtf8("btn200"));
        btn200->setGeometry(QRect(610, 140, 151, 71));
        btn500 = new QPushButton(nostaRahaa);
        btn500->setObjectName(QString::fromUtf8("btn500"));
        btn500->setGeometry(QRect(610, 220, 151, 71));
        btnMuu = new QPushButton(nostaRahaa);
        btnMuu->setObjectName(QString::fromUtf8("btnMuu"));
        btnMuu->setGeometry(QRect(610, 300, 151, 71));
        btnTakaisin = new QPushButton(nostaRahaa);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(610, 380, 151, 71));
        btnOtaRahat = new QPushButton(nostaRahaa);
        btnOtaRahat->setObjectName(QString::fromUtf8("btnOtaRahat"));
        btnOtaRahat->setGeometry(QRect(240, 340, 351, 131));
        btnOtaRahat->setStyleSheet(QString::fromUtf8("border-image: url(:/rahat.png);\n"
"font: 10pt \"Lucida Sans\";\n"
"color: rgb(0, 0, 0);"));
        lineEditMuuSumma = new QLineEdit(nostaRahaa);
        lineEditMuuSumma->setObjectName(QString::fromUtf8("lineEditMuuSumma"));
        lineEditMuuSumma->setGeometry(QRect(280, 240, 261, 61));
        lineEditMuuSumma->setAlignment(Qt::AlignCenter);
        labelMuuSumma = new QLabel(nostaRahaa);
        labelMuuSumma->setObjectName(QString::fromUtf8("labelMuuSumma"));
        labelMuuSumma->setGeometry(QRect(240, 120, 341, 101));
        labelOtsikko = new QLabel(nostaRahaa);
        labelOtsikko->setObjectName(QString::fromUtf8("labelOtsikko"));
        labelOtsikko->setGeometry(QRect(130, 60, 531, 51));
        labelOtsikko->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft Sans Serif\";\n"
"color: rgb(0, 0, 0);\n"
""));

        retranslateUi(nostaRahaa);

        QMetaObject::connectSlotsByName(nostaRahaa);
    } // setupUi

    void retranslateUi(QDialog *nostaRahaa)
    {
        nostaRahaa->setWindowTitle(QCoreApplication::translate("nostaRahaa", "Dialog", nullptr));
        btn20->setText(QCoreApplication::translate("nostaRahaa", "20", nullptr));
        btn40->setText(QCoreApplication::translate("nostaRahaa", "40", nullptr));
        btn60->setText(QCoreApplication::translate("nostaRahaa", "60", nullptr));
        btn100->setText(QCoreApplication::translate("nostaRahaa", "100", nullptr));
        btn200->setText(QCoreApplication::translate("nostaRahaa", "200", nullptr));
        btn500->setText(QCoreApplication::translate("nostaRahaa", "500", nullptr));
        btnMuu->setText(QCoreApplication::translate("nostaRahaa", "Muu summa", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("nostaRahaa", "Takaisin", nullptr));
        btnOtaRahat->setText(QCoreApplication::translate("nostaRahaa", "OTA RAHAT", nullptr));
        labelMuuSumma->setText(QCoreApplication::translate("nostaRahaa", "TextLabel", nullptr));
        labelOtsikko->setText(QCoreApplication::translate("nostaRahaa", "	Paljonkos aattelit nostaa?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nostaRahaa: public Ui_nostaRahaa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOSTARAHAA_H
