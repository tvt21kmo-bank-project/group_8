/********************************************************************************
** Form generated from reading UI file 'valitsetili.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALITSETILI_H
#define UI_VALITSETILI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_valitseTili
{
public:
    QPushButton *btnDebit;
    QPushButton *btnCredit;
    QLabel *labelOtsikko;
    QPushButton *btnTakaisin;

    void setupUi(QDialog *valitseTili)
    {
        if (valitseTili->objectName().isEmpty())
            valitseTili->setObjectName(QString::fromUtf8("valitseTili"));
        valitseTili->resize(803, 567);
        btnDebit = new QPushButton(valitseTili);
        btnDebit->setObjectName(QString::fromUtf8("btnDebit"));
        btnDebit->setGeometry(QRect(330, 220, 171, 61));
        btnCredit = new QPushButton(valitseTili);
        btnCredit->setObjectName(QString::fromUtf8("btnCredit"));
        btnCredit->setGeometry(QRect(330, 310, 171, 61));
        labelOtsikko = new QLabel(valitseTili);
        labelOtsikko->setObjectName(QString::fromUtf8("labelOtsikko"));
        labelOtsikko->setGeometry(QRect(290, 150, 241, 41));
        btnTakaisin = new QPushButton(valitseTili);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(330, 430, 171, 61));

        retranslateUi(valitseTili);

        QMetaObject::connectSlotsByName(valitseTili);
    } // setupUi

    void retranslateUi(QDialog *valitseTili)
    {
        valitseTili->setWindowTitle(QCoreApplication::translate("valitseTili", "Dialog", nullptr));
        btnDebit->setText(QCoreApplication::translate("valitseTili", "DEBIT", nullptr));
        btnCredit->setText(QCoreApplication::translate("valitseTili", "CREDIT", nullptr));
        labelOtsikko->setText(QCoreApplication::translate("valitseTili", "Valitse k\303\244ytett\303\244v\303\244 tili", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("valitseTili", "TAKAISIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class valitseTili: public Ui_valitseTili {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALITSETILI_H
