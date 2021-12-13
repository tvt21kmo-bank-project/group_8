/********************************************************************************
** Form generated from reading UI file 'vaihdatili.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VAIHDATILI_H
#define UI_VAIHDATILI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_vaihdaTili
{
public:
    QPushButton *btnDebit;
    QPushButton *btnCredit;
    QPushButton *btnTakaisin;
    QLabel *labelOtsikko;

    void setupUi(QDialog *vaihdaTili)
    {
        if (vaihdaTili->objectName().isEmpty())
            vaihdaTili->setObjectName(QString::fromUtf8("vaihdaTili"));
        vaihdaTili->resize(548, 396);
        btnDebit = new QPushButton(vaihdaTili);
        btnDebit->setObjectName(QString::fromUtf8("btnDebit"));
        btnDebit->setGeometry(QRect(180, 90, 171, 61));
        btnCredit = new QPushButton(vaihdaTili);
        btnCredit->setObjectName(QString::fromUtf8("btnCredit"));
        btnCredit->setGeometry(QRect(180, 180, 171, 61));
        btnTakaisin = new QPushButton(vaihdaTili);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(180, 300, 171, 61));
        labelOtsikko = new QLabel(vaihdaTili);
        labelOtsikko->setObjectName(QString::fromUtf8("labelOtsikko"));
        labelOtsikko->setGeometry(QRect(140, 20, 241, 41));

        retranslateUi(vaihdaTili);

        QMetaObject::connectSlotsByName(vaihdaTili);
    } // setupUi

    void retranslateUi(QDialog *vaihdaTili)
    {
        vaihdaTili->setWindowTitle(QCoreApplication::translate("vaihdaTili", "Dialog", nullptr));
        btnDebit->setText(QCoreApplication::translate("vaihdaTili", "DEBIT", nullptr));
        btnCredit->setText(QCoreApplication::translate("vaihdaTili", "CREDIT", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("vaihdaTili", "TAKAISIN", nullptr));
        labelOtsikko->setText(QCoreApplication::translate("vaihdaTili", "Valitse k\303\244ytett\303\244v\303\244 tili", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vaihdaTili: public Ui_vaihdaTili {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VAIHDATILI_H
