/********************************************************************************
** Form generated from reading UI file 'selaatilitapahtumia.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELAATILITAPAHTUMIA_H
#define UI_SELAATILITAPAHTUMIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selaaTilitapahtumia
{
public:

    void setupUi(QWidget *selaaTilitapahtumia)
    {
        if (selaaTilitapahtumia->objectName().isEmpty())
            selaaTilitapahtumia->setObjectName(QStringLiteral("selaaTilitapahtumia"));
        selaaTilitapahtumia->resize(400, 300);

        retranslateUi(selaaTilitapahtumia);

        QMetaObject::connectSlotsByName(selaaTilitapahtumia);
    } // setupUi

    void retranslateUi(QWidget *selaaTilitapahtumia)
    {
        selaaTilitapahtumia->setWindowTitle(QApplication::translate("selaaTilitapahtumia", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selaaTilitapahtumia: public Ui_selaaTilitapahtumia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELAATILITAPAHTUMIA_H
