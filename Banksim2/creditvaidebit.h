#ifndef CREDITVAIDEBIT_H
#define CREDITVAIDEBIT_H

#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "menu.h"



namespace Ui {
class creditvaidebit;
}

class creditvaidebit : public QDialog
{
    Q_OBJECT

public:
    explicit creditvaidebit(QWidget *parent = 0);
    ~creditvaidebit();

private slots:
    void on_btncredit_clicked();

    void on_btndebit_clicked();

    void on_btnperuuta_clicked();

private:
    Ui::creditvaidebit *ui;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;
    menu *objmenu;

};

#endif // CREDITVAIDEBIT_H
