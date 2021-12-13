/********************************************************************************
** Form generated from reading UI file 'tilisiirto.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILISIIRTO_H
#define UI_TILISIIRTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_tilisiirto
{
public:
    QPushButton *btnSiirra;
    QPushButton *btnTakaisin;
    QLineEdit *lineTilille;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineSumma;
    QLabel *label_4;
    QTextEdit *textSiirto;
    QCheckBox *checkBox;

    void setupUi(QDialog *tilisiirto)
    {
        if (tilisiirto->objectName().isEmpty())
            tilisiirto->setObjectName(QString::fromUtf8("tilisiirto"));
        tilisiirto->resize(841, 532);
        btnSiirra = new QPushButton(tilisiirto);
        btnSiirra->setObjectName(QString::fromUtf8("btnSiirra"));
        btnSiirra->setGeometry(QRect(300, 320, 101, 71));
        btnTakaisin = new QPushButton(tilisiirto);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(430, 320, 101, 71));
        lineTilille = new QLineEdit(tilisiirto);
        lineTilille->setObjectName(QString::fromUtf8("lineTilille"));
        lineTilille->setGeometry(QRect(300, 80, 241, 41));
        label = new QLabel(tilisiirto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 20, 181, 61));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(tilisiirto);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 140, 271, 51));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(tilisiirto);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 70, 51, 61));
        label_3->setFont(font1);
        lineSumma = new QLineEdit(tilisiirto);
        lineSumma->setObjectName(QString::fromUtf8("lineSumma"));
        lineSumma->setGeometry(QRect(300, 250, 241, 41));
        label_4 = new QLabel(tilisiirto);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 240, 71, 61));
        label_4->setFont(font1);
        textSiirto = new QTextEdit(tilisiirto);
        textSiirto->setObjectName(QString::fromUtf8("textSiirto"));
        textSiirto->setGeometry(QRect(300, 410, 231, 71));
        checkBox = new QCheckBox(tilisiirto);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(390, 180, 81, 61));
        checkBox->setFont(font1);

        retranslateUi(tilisiirto);

        QMetaObject::connectSlotsByName(tilisiirto);
    } // setupUi

    void retranslateUi(QDialog *tilisiirto)
    {
        tilisiirto->setWindowTitle(QCoreApplication::translate("tilisiirto", "Dialog", nullptr));
        btnSiirra->setText(QCoreApplication::translate("tilisiirto", "Siirr\303\244", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("tilisiirto", "Takaisin", nullptr));
        label->setText(QCoreApplication::translate("tilisiirto", "Tilisiirto", nullptr));
        label_2->setText(QCoreApplication::translate("tilisiirto", "Siirret\303\244\303\244nk\303\266 Credit -tilille?", nullptr));
        label_3->setText(QCoreApplication::translate("tilisiirto", "Tilille:", nullptr));
        label_4->setText(QCoreApplication::translate("tilisiirto", "Summa:", nullptr));
        checkBox->setText(QCoreApplication::translate("tilisiirto", "Kyll\303\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tilisiirto: public Ui_tilisiirto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILISIIRTO_H
