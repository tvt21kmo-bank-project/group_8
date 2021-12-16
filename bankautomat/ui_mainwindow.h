/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *btnLueKortti;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditKortti;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(920, 549);
        MainWindow->setStyleSheet(QLatin1String("QWidget#centralWidget\n"
"{\n"
"    background-image: url(:/doge.png);\n"
"}"));
        MainWindow->setInputMethodHints(Qt::ImhHiddenText);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 20, 931, 51));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("font: 12pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 920, 549));
        groupBox->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 0);\n"
"border-color: rgba(0, 0, 0, 0);"));
        btnLueKortti = new QPushButton(groupBox);
        btnLueKortti->setObjectName(QStringLiteral("btnLueKortti"));
        btnLueKortti->setGeometry(QRect(310, 380, 281, 121));
        btnLueKortti->setStyleSheet(QLatin1String("font: 12pt \"MS Reference Sans Serif\";\n"
"\n"
"background-color: rgba(170, 170, 0, 225);\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 130, 921, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Sans"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(7);
        label_2->setFont(font2);
        label_2->setStyleSheet(QLatin1String("\n"
"font: 63 18pt \"Lucida Sans\";\n"
"\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 220, 501, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Sans Unicode"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_3->setFont(font3);
        label_3->setStyleSheet(QLatin1String("\n"
"font: 10pt \"Lucida Sans Unicode\";\n"
"color: rgb(0, 0, 0);"));
        lineEditKortti = new QLineEdit(groupBox);
        lineEditKortti->setObjectName(QStringLiteral("lineEditKortti"));
        lineEditKortti->setGeometry(QRect(320, 270, 261, 91));
        QFont font4;
        font4.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        lineEditKortti->setFont(font4);
        lineEditKortti->setLayoutDirection(Qt::LeftToRight);
        lineEditKortti->setStyleSheet(QLatin1String("background-color: rgba(170, 170, 117, 230);\n"
"border-color: rgb(0, 21, 0);\n"
"gridline-color: rgb(0, 22, 0);\n"
"\n"
"font: 14pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        lineEditKortti->setAlignment(Qt::AlignCenter);
        btnLueKortti->raise();
        lineEditKortti->raise();
        label_3->raise();
        label_2->raise();
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(140, 220, 631, 111));
        label_5->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 16pt \"Lucida Sans\";"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(140, 200, 721, 191));
        label_6->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 12pt \"Lucida Sans\";\n"
""));
        MainWindow->setCentralWidget(centralWidget);
        groupBox->raise();
        label->raise();
        label_5->raise();
        label_6->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
#ifndef QT_NO_ACCESSIBILITY
        centralWidget->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        label->setText(QApplication::translate("MainWindow", "Tarttetko n\303\244\303\244 massia? T\303\244\303\244lt\303\244 sit\303\244 saa", Q_NULLPTR));
        groupBox->setTitle(QString());
        btnLueKortti->setText(QApplication::translate("MainWindow", "LUE KORTTI", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "SY\303\226T\303\204 PANKKIKORTTI", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "(sy\303\266t\303\244 pankkikortin ID-numero)", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Virhe sis\303\244\303\244nkirjautumisessa!\n"
"   Tarkista sy\303\266tetty kortti", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Pin-koodi sy\303\266tetty v\303\244\303\244rin", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
