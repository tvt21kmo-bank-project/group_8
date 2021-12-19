/********************************************************************************
** Form generated from reading UI file 'vaihdatili.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VAIHDATILI_H
#define UI_VAIHDATILI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
            vaihdaTili->setObjectName(QStringLiteral("vaihdaTili"));
        vaihdaTili->resize(548, 396);
        btnDebit = new QPushButton(vaihdaTili);
        btnDebit->setObjectName(QStringLiteral("btnDebit"));
        btnDebit->setGeometry(QRect(180, 90, 171, 61));
        btnCredit = new QPushButton(vaihdaTili);
        btnCredit->setObjectName(QStringLiteral("btnCredit"));
        btnCredit->setGeometry(QRect(180, 180, 171, 61));
        btnTakaisin = new QPushButton(vaihdaTili);
        btnTakaisin->setObjectName(QStringLiteral("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(180, 300, 171, 61));
        labelOtsikko = new QLabel(vaihdaTili);
        labelOtsikko->setObjectName(QStringLiteral("labelOtsikko"));
        labelOtsikko->setGeometry(QRect(130, 20, 531, 51));
        labelOtsikko->setStyleSheet(QLatin1String("font: 10pt \"Microsoft Sans Serif\";\n"
                                                  "color: rgb(0, 0, 0);\n"
                                                  ""));
        retranslateUi(vaihdaTili);

        QMetaObject::connectSlotsByName(vaihdaTili);
    } // setupUi

    void retranslateUi(QDialog *vaihdaTili)
    {
        vaihdaTili->setWindowTitle(QApplication::translate("vaihdaTili", "Dialog", Q_NULLPTR));
        btnDebit->setText(QApplication::translate("vaihdaTili", "DEBIT", Q_NULLPTR));
        btnCredit->setText(QApplication::translate("vaihdaTili", "CREDIT", Q_NULLPTR));
        btnTakaisin->setText(QApplication::translate("vaihdaTili", "TAKAISIN", Q_NULLPTR));
        labelOtsikko->setText(QApplication::translate("vaihdaTili", "Valitse käytettävä tili", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class vaihdaTili: public Ui_vaihdaTili {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VAIHDATILI_H
