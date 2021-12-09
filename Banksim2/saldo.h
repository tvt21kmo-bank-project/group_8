#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "mainwindow.h"


namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(QWidget *parent = 0);
    ~saldo();

private slots:
    void on_pushButton_clicked();

    void on_btnpois_clicked();

private:
    Ui::saldo *ui;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;



};

#endif // SALDO_H
