#ifndef TILISIIRTO_H
#define TILISIIRTO_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QtNetwork>
#include <QString>
#include <QNetworkAccessManager>

namespace Ui {
class tilisiirto;
}

class tilisiirto : public QDialog
{
    Q_OBJECT

public:
    explicit tilisiirto(QWidget *parent, int, bool, int);
    ~tilisiirto();
    void setupUI(QString);

private slots:
    void on_btnSiirra_clicked();
    void siirtoTehty(QNetworkReply *reply);
    void on_btnTakaisin_clicked();

private:
    Ui::tilisiirto *ui;
    int tilinumero1;
    bool creditValittu;
    int korttinumero;
    bool checkerBoxValittu;
    double saldoUlos;
    QTimer *objTimer;
    QNetworkAccessManager *tilisiirtoManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // TILISIIRTO_H
