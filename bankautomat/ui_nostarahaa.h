/********************************************************************************
** Form generated from reading UI file 'nostarahaa.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOSTARAHAA_H
#define UI_NOSTARAHAA_H

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
            nostaRahaa->setObjectName(QStringLiteral("nostaRahaa"));
        nostaRahaa->resize(852, 600);
        btn20 = new QPushButton(nostaRahaa);
        btn20->setObjectName(QStringLiteral("btn20"));
        btn20->setGeometry(QRect(70, 140, 151, 71));
        btn40 = new QPushButton(nostaRahaa);
        btn40->setObjectName(QStringLiteral("btn40"));
        btn40->setGeometry(QRect(70, 220, 151, 71));
        btn60 = new QPushButton(nostaRahaa);
        btn60->setObjectName(QStringLiteral("btn60"));
        btn60->setGeometry(QRect(70, 300, 151, 71));
        btn100 = new QPushButton(nostaRahaa);
        btn100->setObjectName(QStringLiteral("btn100"));
        btn100->setGeometry(QRect(70, 380, 151, 71));
        btn200 = new QPushButton(nostaRahaa);
        btn200->setObjectName(QStringLiteral("btn200"));
        btn200->setGeometry(QRect(610, 140, 151, 71));
        btn500 = new QPushButton(nostaRahaa);
        btn500->setObjectName(QStringLiteral("btn500"));
        btn500->setGeometry(QRect(610, 220, 151, 71));
        btnMuu = new QPushButton(nostaRahaa);
        btnMuu->setObjectName(QStringLiteral("btnMuu"));
        btnMuu->setGeometry(QRect(610, 300, 151, 71));
        btnTakaisin = new QPushButton(nostaRahaa);
        btnTakaisin->setObjectName(QStringLiteral("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(610, 380, 151, 71));
        btnOtaRahat = new QPushButton(nostaRahaa);
        btnOtaRahat->setObjectName(QStringLiteral("btnOtaRahat"));
        btnOtaRahat->setGeometry(QRect(240, 340, 351, 131));
        btnOtaRahat->setStyleSheet(QLatin1String("border-image: url(:/rahat.png);\n"
"font: 10pt \"Lucida Sans\";\n"
"color: rgb(0, 0, 0);"));
        lineEditMuuSumma = new QLineEdit(nostaRahaa);
        lineEditMuuSumma->setObjectName(QStringLiteral("lineEditMuuSumma"));
        lineEditMuuSumma->setGeometry(QRect(280, 240, 261, 61));
        lineEditMuuSumma->setAlignment(Qt::AlignCenter);
        labelMuuSumma = new QLabel(nostaRahaa);
        labelMuuSumma->setObjectName(QStringLiteral("labelMuuSumma"));
        labelMuuSumma->setGeometry(QRect(240, 120, 341, 101));
        labelOtsikko = new QLabel(nostaRahaa);
        labelOtsikko->setObjectName(QStringLiteral("labelOtsikko"));
        labelOtsikko->setGeometry(QRect(130, 60, 531, 51));
        labelOtsikko->setStyleSheet(QLatin1String("font: 12pt \"Microsoft Sans Serif\";\n"
"color: rgb(0, 0, 0);\n"
""));

        retranslateUi(nostaRahaa);

        QMetaObject::connectSlotsByName(nostaRahaa);
    } // setupUi

    void retranslateUi(QDialog *nostaRahaa)
    {
        nostaRahaa->setWindowTitle(QApplication::translate("nostaRahaa", "Dialog", Q_NULLPTR));
        btn20->setText(QApplication::translate("nostaRahaa", "20", Q_NULLPTR));
        btn40->setText(QApplication::translate("nostaRahaa", "40", Q_NULLPTR));
        btn60->setText(QApplication::translate("nostaRahaa", "60", Q_NULLPTR));
        btn100->setText(QApplication::translate("nostaRahaa", "100", Q_NULLPTR));
        btn200->setText(QApplication::translate("nostaRahaa", "200", Q_NULLPTR));
        btn500->setText(QApplication::translate("nostaRahaa", "500", Q_NULLPTR));
        btnMuu->setText(QApplication::translate("nostaRahaa", "Muu summa", Q_NULLPTR));
        btnTakaisin->setText(QApplication::translate("nostaRahaa", "Takaisin", Q_NULLPTR));
        btnOtaRahat->setText(QApplication::translate("nostaRahaa", "OTA RAHAT", Q_NULLPTR));
        labelMuuSumma->setText(QApplication::translate("nostaRahaa", "TextLabel", Q_NULLPTR));
        labelOtsikko->setText(QApplication::translate("nostaRahaa", "	Paljonkos aattelit nostaa?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nostaRahaa: public Ui_nostaRahaa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOSTARAHAA_H
