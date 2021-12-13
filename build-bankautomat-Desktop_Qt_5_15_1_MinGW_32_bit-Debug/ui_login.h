/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEditLogin;
    QLabel *label;
    QPushButton *btnLogin;
    QLabel *label_2;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(898, 630);
        groupBox = new QGroupBox(login);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 920, 641));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"selection-background-color:gba(0, 0, 0, 0);\n"
"selection-color: gba(0, 0, 0, 0);\n"
"gridline-color: gba(0, 0, 0, 0);\n"
"border-color: rgba(0, 0, 0, 0);"));
        lineEditLogin = new QLineEdit(groupBox);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));
        lineEditLogin->setGeometry(QRect(320, 340, 261, 91));
        lineEditLogin->setStyleSheet(QString::fromUtf8("background-color: rgba(170, 170, 117, 230);\n"
"border-color: rgb(0, 21, 0);\n"
"gridline-color: rgb(0, 22, 0);\n"
"\n"
"font: 14pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        lineEditLogin->setEchoMode(QLineEdit::Password);
        lineEditLogin->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 265, 500, 50));
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 14pt \"Lucida Sans Unicode\";\n"
"color: rgb(0, 0, 0);"));
        btnLogin = new QPushButton(groupBox);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(310, 450, 281, 121));
        btnLogin->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Reference Sans Serif\";\n"
"\n"
"background-color: rgba(170, 170, 0, 225);\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 240, 601, 181));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 14pt \"Lucida Sans Unicode\";\n"
""));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("login", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("login", "SY\303\226T\303\204 PIN-KOODI", nullptr));
        btnLogin->setText(QCoreApplication::translate("login", "KIRJAUDU", nullptr));
        label_2->setText(QCoreApplication::translate("login", "        V\303\204\303\204R\303\204 PIN-KOODI\n"
" Ole hyv\303\244 ja yrit\303\244 uudestaan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
