/********************************************************************************
** Form generated from reading UI file 'luepin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUEPIN_H
#define UI_LUEPIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_luepin
{
public:
    QLabel *label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(645, 423);
        Form->setStyleSheet(QStringLiteral("image: url(:/doge.png);"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 100, 47, 14));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("luepin", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("luepin", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class luepin: public Ui_luepin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUEPIN_H
