/********************************************************************************
** Form generated from reading UI file 'naytatapahtumia.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAYTATAPAHTUMIA_H
#define UI_NAYTATAPAHTUMIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_naytaTapahtumia
{
public:
    QPushButton *btnEdelliset;
    QPushButton *btnSeuraavat;
    QPushButton *btnTakaisin;
    QLabel *labelOtsikko;
    QGroupBox *groupBoxTilitiedot;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTilitiedot1;
    QLabel *labelTilitiedot_tilinumero;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelTilitiedot2;
    QLabel *labelTilitiedot_tilinOmistaja;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelTilitiedot3;
    QLabel *labelTilitiedot_tilityyppi;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelTilitiedot4;
    QLabel *labelTilitiedot_tilinSaldo;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEditAikaleima;
    QTextEdit *textEditSumma;
    QTextEdit *textEditTapahtumatyyppi;
    QTextEdit *textEditMaksaja;

    void setupUi(QDialog *naytaTapahtumia)
    {
        if (naytaTapahtumia->objectName().isEmpty())
            naytaTapahtumia->setObjectName(QString::fromUtf8("naytaTapahtumia"));
        naytaTapahtumia->resize(852, 636);
        btnEdelliset = new QPushButton(naytaTapahtumia);
        btnEdelliset->setObjectName(QString::fromUtf8("btnEdelliset"));
        btnEdelliset->setGeometry(QRect(40, 550, 251, 71));
        btnSeuraavat = new QPushButton(naytaTapahtumia);
        btnSeuraavat->setObjectName(QString::fromUtf8("btnSeuraavat"));
        btnSeuraavat->setGeometry(QRect(310, 550, 251, 71));
        btnTakaisin = new QPushButton(naytaTapahtumia);
        btnTakaisin->setObjectName(QString::fromUtf8("btnTakaisin"));
        btnTakaisin->setGeometry(QRect(700, 550, 141, 71));
        labelOtsikko = new QLabel(naytaTapahtumia);
        labelOtsikko->setObjectName(QString::fromUtf8("labelOtsikko"));
        labelOtsikko->setGeometry(QRect(30, 10, 721, 41));
        QFont font;
        font.setPointSize(10);
        labelOtsikko->setFont(font);
        groupBoxTilitiedot = new QGroupBox(naytaTapahtumia);
        groupBoxTilitiedot->setObjectName(QString::fromUtf8("groupBoxTilitiedot"));
        groupBoxTilitiedot->setGeometry(QRect(30, 60, 821, 101));
        verticalLayoutWidget = new QWidget(groupBoxTilitiedot);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 821, 84));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelTilitiedot1 = new QLabel(verticalLayoutWidget);
        labelTilitiedot1->setObjectName(QString::fromUtf8("labelTilitiedot1"));

        horizontalLayout_2->addWidget(labelTilitiedot1);

        labelTilitiedot_tilinumero = new QLabel(verticalLayoutWidget);
        labelTilitiedot_tilinumero->setObjectName(QString::fromUtf8("labelTilitiedot_tilinumero"));

        horizontalLayout_2->addWidget(labelTilitiedot_tilinumero);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        labelTilitiedot2 = new QLabel(verticalLayoutWidget);
        labelTilitiedot2->setObjectName(QString::fromUtf8("labelTilitiedot2"));

        horizontalLayout_2->addWidget(labelTilitiedot2);

        labelTilitiedot_tilinOmistaja = new QLabel(verticalLayoutWidget);
        labelTilitiedot_tilinOmistaja->setObjectName(QString::fromUtf8("labelTilitiedot_tilinOmistaja"));

        horizontalLayout_2->addWidget(labelTilitiedot_tilinOmistaja);

        horizontalSpacer_3 = new QSpacerItem(200, 36, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelTilitiedot3 = new QLabel(verticalLayoutWidget);
        labelTilitiedot3->setObjectName(QString::fromUtf8("labelTilitiedot3"));

        horizontalLayout_4->addWidget(labelTilitiedot3);

        labelTilitiedot_tilityyppi = new QLabel(verticalLayoutWidget);
        labelTilitiedot_tilityyppi->setObjectName(QString::fromUtf8("labelTilitiedot_tilityyppi"));

        horizontalLayout_4->addWidget(labelTilitiedot_tilityyppi);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        labelTilitiedot4 = new QLabel(verticalLayoutWidget);
        labelTilitiedot4->setObjectName(QString::fromUtf8("labelTilitiedot4"));

        horizontalLayout_4->addWidget(labelTilitiedot4);

        labelTilitiedot_tilinSaldo = new QLabel(verticalLayoutWidget);
        labelTilitiedot_tilinSaldo->setObjectName(QString::fromUtf8("labelTilitiedot_tilinSaldo"));

        horizontalLayout_4->addWidget(labelTilitiedot_tilinSaldo);

        horizontalSpacer = new QSpacerItem(200, 36, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(naytaTapahtumia);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 180, 821, 361));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 838, 341));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textEditAikaleima = new QTextEdit(horizontalLayoutWidget);
        textEditAikaleima->setObjectName(QString::fromUtf8("textEditAikaleima"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(40);
        sizePolicy.setHeightForWidth(textEditAikaleima->sizePolicy().hasHeightForWidth());
        textEditAikaleima->setSizePolicy(sizePolicy);
        textEditAikaleima->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        textEditAikaleima->setFrameShape(QFrame::NoFrame);
        textEditAikaleima->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditAikaleima->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditAikaleima->setReadOnly(true);

        horizontalLayout->addWidget(textEditAikaleima);

        textEditSumma = new QTextEdit(horizontalLayoutWidget);
        textEditSumma->setObjectName(QString::fromUtf8("textEditSumma"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEditSumma->sizePolicy().hasHeightForWidth());
        textEditSumma->setSizePolicy(sizePolicy1);
        textEditSumma->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        textEditSumma->setFrameShape(QFrame::NoFrame);
        textEditSumma->setLineWidth(0);
        textEditSumma->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditSumma->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditSumma->setReadOnly(true);

        horizontalLayout->addWidget(textEditSumma);

        textEditTapahtumatyyppi = new QTextEdit(horizontalLayoutWidget);
        textEditTapahtumatyyppi->setObjectName(QString::fromUtf8("textEditTapahtumatyyppi"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(15);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEditTapahtumatyyppi->sizePolicy().hasHeightForWidth());
        textEditTapahtumatyyppi->setSizePolicy(sizePolicy2);
        textEditTapahtumatyyppi->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        textEditTapahtumatyyppi->setFrameShape(QFrame::NoFrame);
        textEditTapahtumatyyppi->setLineWidth(0);
        textEditTapahtumatyyppi->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditTapahtumatyyppi->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditTapahtumatyyppi->setReadOnly(true);

        horizontalLayout->addWidget(textEditTapahtumatyyppi);

        textEditMaksaja = new QTextEdit(horizontalLayoutWidget);
        textEditMaksaja->setObjectName(QString::fromUtf8("textEditMaksaja"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEditMaksaja->sizePolicy().hasHeightForWidth());
        textEditMaksaja->setSizePolicy(sizePolicy3);
        textEditMaksaja->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        textEditMaksaja->setFrameShape(QFrame::NoFrame);
        textEditMaksaja->setLineWidth(0);
        textEditMaksaja->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditMaksaja->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditMaksaja->setReadOnly(true);

        horizontalLayout->addWidget(textEditMaksaja);


        retranslateUi(naytaTapahtumia);

        QMetaObject::connectSlotsByName(naytaTapahtumia);
    } // setupUi

    void retranslateUi(QDialog *naytaTapahtumia)
    {
        naytaTapahtumia->setWindowTitle(QCoreApplication::translate("naytaTapahtumia", "Dialog", nullptr));
        btnEdelliset->setText(QCoreApplication::translate("naytaTapahtumia", "Edelliset tapahtumat", nullptr));
        btnSeuraavat->setText(QCoreApplication::translate("naytaTapahtumia", "Seuraavat tapahtumat", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("naytaTapahtumia", "Takaisin", nullptr));
        labelOtsikko->setText(QCoreApplication::translate("naytaTapahtumia", "TILITAPAHTUMAT ", nullptr));
        groupBoxTilitiedot->setTitle(QCoreApplication::translate("naytaTapahtumia", "Tilitiedot", nullptr));
        labelTilitiedot1->setText(QCoreApplication::translate("naytaTapahtumia", "Tilinumero:", nullptr));
        labelTilitiedot_tilinumero->setText(QString());
        labelTilitiedot2->setText(QCoreApplication::translate("naytaTapahtumia", "Tilin omistaja:", nullptr));
        labelTilitiedot_tilinOmistaja->setText(QString());
        labelTilitiedot3->setText(QCoreApplication::translate("naytaTapahtumia", "Tilityyppi:", nullptr));
        labelTilitiedot_tilityyppi->setText(QString());
        labelTilitiedot4->setText(QCoreApplication::translate("naytaTapahtumia", "Tilin saldo:", nullptr));
        labelTilitiedot_tilinSaldo->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("naytaTapahtumia", "Tilitapahtumat", nullptr));
        textEditTapahtumatyyppi->setDocumentTitle(QCoreApplication::translate("naytaTapahtumia", "Tapahtumatyyppi", nullptr));
        textEditMaksaja->setDocumentTitle(QCoreApplication::translate("naytaTapahtumia", "Maksaja/saaja", nullptr));
    } // retranslateUi

};

namespace Ui {
    class naytaTapahtumia: public Ui_naytaTapahtumia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAYTATAPAHTUMIA_H
