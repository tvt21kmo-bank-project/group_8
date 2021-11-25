/********************************************************************************
** Form generated from reading UI file 'nappiversio.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAPPIVERSIO_H
#define UI_NAPPIVERSIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_24;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_21;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_16;
    QPushButton *pushButton_20;
    QPushButton *pushButton_19;
    QPushButton *pushButton_8;
    QPushButton *pushButton_15;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QGraphicsView *graphicsView_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QWidget *nappiversio)
    {
        if (nappiversio->objectName().isEmpty())
            nappiversio->setObjectName(QStringLiteral("nappiversio"));
        nappiversio->resize(1200, 1000);
        nappiversio->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(nappiversio);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(220, 10, 751, 501));
        graphicsView->setStyleSheet(QStringLiteral("background-image: url(:/doge.png);"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(370, 300, 441, 91));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(99, 99, 99);"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(280, 510, 631, 421));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoRepeatInterval(96);

        gridLayout_3->addWidget(pushButton_7, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 1, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));

        gridLayout->addWidget(pushButton_24, 3, 1, 1, 1);

        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setStyleSheet(QStringLiteral("background-color: rgb(120, 122, 15);"));

        gridLayout->addWidget(pushButton_22, 1, 3, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setStyleSheet(QStringLiteral("background-color: rgb(168, 6, 6);"));

        gridLayout->addWidget(pushButton_23, 2, 3, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setStyleSheet(QStringLiteral("background-color: rgb(0, 85, 0);"));

        gridLayout_4->addWidget(pushButton_21, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 0, 3, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout->addWidget(pushButton_16, 0, 2, 1, 1);

        pushButton_20 = new QPushButton(gridLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_20, 2, 2, 1, 1);

        pushButton_19 = new QPushButton(gridLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        gridLayout->addWidget(pushButton_19, 1, 2, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 2, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_2->addWidget(pushButton_6, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 10, 131, 511));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout_2->addWidget(pushButton_9);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(180, 50, 111, 431));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(-235, -179, 1481, 1321));
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(1010, 10, 131, 511));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(verticalLayoutWidget_3);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout_4->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(verticalLayoutWidget_3);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        verticalLayout_4->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(verticalLayoutWidget_3);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout_4->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(verticalLayoutWidget_3);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        verticalLayout_4->addWidget(pushButton_13);

        verticalLayoutWidget_4 = new QWidget(centralWidget);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(890, 50, 121, 431));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_5->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(360, 80, 511, 51));
        graphicsView_2->raise();
        graphicsView->raise();
        lineEdit->raise();
        gridLayoutWidget->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        verticalLayoutWidget_3->raise();
        verticalLayoutWidget_4->raise();
        label_9->raise();
        menuBar = new QMenuBar(nappiversio);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 21));
        mainToolBar = new QToolBar(nappiversio);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        statusBar = new QStatusBar(nappiversio);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        toolBar = new QToolBar(nappiversio);
        toolBar->setObjectName(QStringLiteral("toolBar"));

        retranslateUi(nappiversio);

        QMetaObject::connectSlotsByName(nappiversio);
    } // setupUi

    void retranslateUi(QWidget *nappiversio)
    {
        nappiversio->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Form", "2", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("Form", "Tyhjenn\303\244", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("Form", "PYS\303\204YT\303\204", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("Form", "Hyv\303\244ksy", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Form", "1", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Form", "4", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("Form", "3", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("Form", "9", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("Form", "6", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Form", "5", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("Form", "8", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Form", "7", Q_NULLPTR));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_9->setText(QString());
        pushButton->setText(QString());
        label_2->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        label_5->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_9->setText(QApplication::translate("Form", "Tervetuloa ", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("Form", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAPPIVERSIO_H
