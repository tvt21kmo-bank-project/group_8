/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
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
            login->setObjectName(QStringLiteral("login"));
        login->resize(898, 630);
        groupBox = new QGroupBox(login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 920, 641));
        groupBox->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 0);\n"
"selection-background-color:gba(0, 0, 0, 0);\n"
"selection-color: gba(0, 0, 0, 0);\n"
"gridline-color: gba(0, 0, 0, 0);\n"
"border-color: rgba(0, 0, 0, 0);"));
        lineEditLogin = new QLineEdit(groupBox);
        lineEditLogin->setObjectName(QStringLiteral("lineEditLogin"));
        lineEditLogin->setGeometry(QRect(330, 335, 261, 91));
        lineEditLogin->setStyleSheet(QLatin1String("background-color: rgba(170, 170, 117, 230);\n"
"border-color: rgb(0, 21, 0);\n"
"gridline-color: rgb(0, 22, 0);\n"
"\n"
"font: 14pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        lineEditLogin->setEchoMode(QLineEdit::Password);
        lineEditLogin->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 260, 500, 50));
        label->setStyleSheet(QLatin1String("\n"
"font: 14pt \"Lucida Sans Unicode\";\n"
"color: rgb(0, 0, 0);"));
        btnLogin = new QPushButton(groupBox);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));
        btnLogin->setGeometry(QRect(320, 445, 281, 121));
        btnLogin->setStyleSheet(QLatin1String("font: 12pt \"MS Reference Sans Serif\";\n"
"\n"
"background-color: rgba(170, 170, 0, 225);\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 240, 601, 181));
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 14pt \"Lucida Sans Unicode\";\n"
""));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("login", "GroupBox", Q_NULLPTR));
        label->setText(QApplication::translate("login", "SY\303\226T\303\204 PIN-KOODI", Q_NULLPTR));
        btnLogin->setText(QApplication::translate("login", "KIRJAUDU", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "        V\303\204\303\204R\303\204 PIN-KOODI\n"
" Ole hyv\303\244 ja yrit\303\244 uudestaan", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
