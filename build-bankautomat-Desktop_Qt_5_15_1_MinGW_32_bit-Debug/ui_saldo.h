/********************************************************************************
** Form generated from reading UI file 'saldo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDO_H
#define UI_SALDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saldo
{
public:
    QPushButton *btnTakaisin;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelOtsikkoKortti;
    QLabel *labelKorttiNumero;
    QLabel *labelKorttityyppi;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelOtsikkoSaldo;
    QLabel *labelNostettavaSaldo;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelOtsikkoTili;
    QLabel *labelTilinumero;
    QLabel *labelTiliOmistaja;
    QLabel *labelPvm;
    QLabel *labelOtsikko;
    QLabel *labelKlo;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelSaldo;
    QLabel *labelLuottoraja;

    void setupUi(QDialog *saldo)
    {
        if (saldo->objectName().isEmpty())
            saldo->setObjectName(QString::fromUtf8("saldo"));
        saldo->resize(846, 594);
        btnTakaisin = new QPushButton(saldo);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(570, 440, 161, 71));
        horizontalLayoutWidget = new QWidget(saldo);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(160, 240, 581, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelOtsikkoKortti = new QLabel(horizontalLayoutWidget);
        labelOtsikkoKortti->setObjectName(QString::fromUtf8("labelOtsikkoKortti"));

        horizontalLayout->addWidget(labelOtsikkoKortti);

        labelKorttiNumero = new QLabel(horizontalLayoutWidget);
        labelKorttiNumero->setObjectName(QString::fromUtf8("labelKorttiNumero"));

        horizontalLayout->addWidget(labelKorttiNumero);

        labelKorttityyppi = new QLabel(horizontalLayoutWidget);
        labelKorttityyppi->setObjectName(QString::fromUtf8("labelKorttityyppi"));

        horizontalLayout->addWidget(labelKorttityyppi);

        horizontalLayoutWidget_3 = new QWidget(saldo);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(160, 320, 391, 61));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelOtsikkoSaldo = new QLabel(horizontalLayoutWidget_3);
        labelOtsikkoSaldo->setObjectName(QString::fromUtf8("labelOtsikkoSaldo"));

        horizontalLayout_3->addWidget(labelOtsikkoSaldo);

        labelNostettavaSaldo = new QLabel(horizontalLayoutWidget_3);
        labelNostettavaSaldo->setObjectName(QString::fromUtf8("labelNostettavaSaldo"));

        horizontalLayout_3->addWidget(labelNostettavaSaldo);

        horizontalLayoutWidget_2 = new QWidget(saldo);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(160, 280, 581, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelOtsikkoTili = new QLabel(horizontalLayoutWidget_2);
        labelOtsikkoTili->setObjectName(QString::fromUtf8("labelOtsikkoTili"));

        horizontalLayout_2->addWidget(labelOtsikkoTili);

        labelTilinumero = new QLabel(horizontalLayoutWidget_2);
        labelTilinumero->setObjectName(QString::fromUtf8("labelTilinumero"));

        horizontalLayout_2->addWidget(labelTilinumero);

        labelTiliOmistaja = new QLabel(horizontalLayoutWidget_2);
        labelTiliOmistaja->setObjectName(QString::fromUtf8("labelTiliOmistaja"));

        horizontalLayout_2->addWidget(labelTiliOmistaja);

        labelPvm = new QLabel(saldo);
        labelPvm->setObjectName(QString::fromUtf8("labelPvm"));
        labelPvm->setGeometry(QRect(160, 175, 251, 21));
        labelOtsikko = new QLabel(saldo);
        labelOtsikko->setObjectName(QString::fromUtf8("labelOtsikko"));
        labelOtsikko->setGeometry(QRect(230, 80, 261, 61));
        QFont font;
        font.setPointSize(12);
        labelOtsikko->setFont(font);
        labelKlo = new QLabel(saldo);
        labelKlo->setObjectName(QString::fromUtf8("labelKlo"));
        labelKlo->setGeometry(QRect(160, 205, 231, 21));
        horizontalLayoutWidget_4 = new QWidget(saldo);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(160, 320, 391, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelSaldo = new QLabel(horizontalLayoutWidget_4);
        labelSaldo->setObjectName(QString::fromUtf8("labelSaldo"));

        horizontalLayout_4->addWidget(labelSaldo);

        labelLuottoraja = new QLabel(horizontalLayoutWidget_4);
        labelLuottoraja->setObjectName(QString::fromUtf8("labelLuottoraja"));

        horizontalLayout_4->addWidget(labelLuottoraja);


        retranslateUi(saldo);

        QMetaObject::connectSlotsByName(saldo);
    } // setupUi

    void retranslateUi(QDialog *saldo)
    {
        saldo->setWindowTitle(QCoreApplication::translate("saldo", "Dialog", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("saldo", "Takaisin", nullptr));
        labelOtsikkoKortti->setText(QCoreApplication::translate("saldo", "Pankkikortti", nullptr));
        labelKorttiNumero->setText(QCoreApplication::translate("saldo", "Numero: ", nullptr));
        labelKorttityyppi->setText(QString());
        labelOtsikkoSaldo->setText(QCoreApplication::translate("saldo", "Tililt\303\244 nostettavissa oleva saldo:", nullptr));
        labelNostettavaSaldo->setText(QString());
        labelOtsikkoTili->setText(QCoreApplication::translate("saldo", "Pankkitili", nullptr));
        labelTilinumero->setText(QCoreApplication::translate("saldo", "Numero: ", nullptr));
        labelTiliOmistaja->setText(QCoreApplication::translate("saldo", "Omistaja: ", nullptr));
        labelPvm->setText(QCoreApplication::translate("saldo", "Pvm: ", nullptr));
        labelOtsikko->setText(QCoreApplication::translate("saldo", "SALDO", nullptr));
        labelKlo->setText(QCoreApplication::translate("saldo", "Klo: ", nullptr));
        labelSaldo->setText(QCoreApplication::translate("saldo", "Saldo: ", nullptr));
        labelLuottoraja->setText(QCoreApplication::translate("saldo", "Luottoraja: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saldo: public Ui_saldo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDO_H
