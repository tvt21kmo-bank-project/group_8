#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QtNetwork>
#include <QNetworkAccessManager>

namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(QWidget *parent, int, bool, int);
    ~saldo();
    void haeTiedot();

private slots:
    void on_btnTakaisin_clicked();
    void naytaTiedot(QNetworkReply *reply);

private:
    Ui::saldo *ui;
    int korttinumero;
    int tilinumero;
    bool creditValittu;
    QTimer *objTimer;
    QNetworkAccessManager *saldoManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // SALDO_H
