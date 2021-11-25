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
    QPushButton *btnLueKortti;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditKortti;
    QLabel *label_4;
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
        btnLueKortti = new QPushButton(centralWidget);
        btnLueKortti->setObjectName(QStringLiteral("btnLueKortti"));
        btnLueKortti->setGeometry(QRect(310, 380, 281, 121));
        btnLueKortti->setStyleSheet(QLatin1String("font: 12pt \"MS Reference Sans Serif\";\n"
"\n"
"background-color: rgba(170, 170, 0, 225);\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 130, 921, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Sans"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(7);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("\n"
"font: 63 18pt \"Lucida Sans\";\n"
"\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 220, 501, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Sans Unicode"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_3->setFont(font2);
        label_3->setStyleSheet(QLatin1String("\n"
"font: 8pt \"Lucida Sans Unicode\";\n"
"color: rgb(0, 0, 0);"));
        lineEditKortti = new QLineEdit(centralWidget);
        lineEditKortti->setObjectName(QStringLiteral("lineEditKortti"));
        lineEditKortti->setGeometry(QRect(320, 270, 261, 91));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        lineEditKortti->setFont(font3);
        lineEditKortti->setLayoutDirection(Qt::LeftToRight);
        lineEditKortti->setStyleSheet(QLatin1String("background-color: rgba(170, 170, 117, 230);\n"
"border-color: rgb(0, 21, 0);\n"
"gridline-color: rgb(0, 22, 0);\n"
"\n"
"font: 14pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        lineEditKortti->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 520, 811, 21));
        QFont font4;
        font4.setPointSize(7);
        label_4->setFont(font4);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(false);
        label_5->setGeometry(QRect(140, 140, 631, 111));
        label_5->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 16pt \"Lucida Sans\";"));
        label_5->setInputMethodHints(Qt::ImhNone);
        label_5->setScaledContents(false);
        label_5->setMargin(0);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(false);
        label_6->setGeometry(QRect(120, 140, 721, 191));
        label_6->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 12pt \"Lucida Sans\";"));
        label_6->setInputMethodHints(Qt::ImhNone);
        label_6->setScaledContents(false);
        label_6->setMargin(0);
        MainWindow->setCentralWidget(centralWidget);
        label_5->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        lineEditKortti->raise();
        btnLueKortti->raise();
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
        btnLueKortti->setText(QApplication::translate("MainWindow", "LUE KORTTI", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "SY\303\226T\303\204 PANKKIKORTTI", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "(sy\303\266t\303\244 pankkikortin ID-numero)", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "*formlayout on karkeaversio toiminnallisuuksien testausta varten*", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Virhe sis\303\244\303\244nkirjautumisessa!\n"
"   Tarkista sy\303\266tetty kortti", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "	V\303\204\303\204R\303\204 PIN-KOODI\n"
"\n"
"Pin-koodi sy\303\266tetty v\303\244\303\244rin liian monta kertaa\n"
"  KorttiID# on poistettu k\303\244yt\303\266st\303\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
