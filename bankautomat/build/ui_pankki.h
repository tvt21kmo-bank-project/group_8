/********************************************************************************
** Form generated from reading UI file 'pankki.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANKKI_H
#define UI_PANKKI_H

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

class Ui_pankki
{
public:
    QLineEdit *leId1;
    QLineEdit *leId2;
    QLineEdit *leSumma;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btnSiirto;
    QLabel *labelDebitInfo;

    void setupUi(QDialog *pankki)
    {
        if (pankki->objectName().isEmpty())
            pankki->setObjectName(QStringLiteral("pankki"));
        pankki->resize(400, 300);
        leId1 = new QLineEdit(pankki);
        leId1->setObjectName(QStringLiteral("leId1"));
        leId1->setGeometry(QRect(40, 40, 113, 21));
        leId2 = new QLineEdit(pankki);
        leId2->setObjectName(QStringLiteral("leId2"));
        leId2->setGeometry(QRect(40, 130, 113, 21));
        leSumma = new QLineEdit(pankki);
        leSumma->setObjectName(QStringLiteral("leSumma"));
        leSumma->setGeometry(QRect(40, 220, 113, 21));
        label = new QLabel(pankki);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 47, 13));
        label_2 = new QLabel(pankki);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 100, 47, 13));
        label_3 = new QLabel(pankki);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 190, 47, 13));
        label_4 = new QLabel(pankki);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 20, 161, 61));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);
        btnSiirto = new QPushButton(pankki);
        btnSiirto->setObjectName(QStringLiteral("btnSiirto"));
        btnSiirto->setGeometry(QRect(200, 130, 80, 21));
        labelDebitInfo = new QLabel(pankki);
        labelDebitInfo->setObjectName(QStringLiteral("labelDebitInfo"));
        labelDebitInfo->setGeometry(QRect(200, 90, 91, 16));

        retranslateUi(pankki);

        QMetaObject::connectSlotsByName(pankki);
    } // setupUi

    void retranslateUi(QDialog *pankki)
    {
        pankki->setWindowTitle(QApplication::translate("pankki", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("pankki", "Tililt\303\244:", Q_NULLPTR));
        label_2->setText(QApplication::translate("pankki", "Tilille", Q_NULLPTR));
        label_3->setText(QApplication::translate("pankki", "Summa", Q_NULLPTR));
        label_4->setText(QApplication::translate("pankki", "Tilisiirto", Q_NULLPTR));
        btnSiirto->setText(QApplication::translate("pankki", "Siirr\303\244", Q_NULLPTR));
        labelDebitInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pankki: public Ui_pankki {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANKKI_H
