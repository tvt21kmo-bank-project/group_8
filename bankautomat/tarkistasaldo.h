#ifndef TARKISTASALDO_H
#define TARKISTASALDO_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QtNetwork>
#include <QNetworkAccessManager>

namespace Ui {
class tarkistaSaldo;
}

class tarkistaSaldo : public QDialog
{
    Q_OBJECT

public:
    explicit tarkistaSaldo(QWidget *parent, int, int, bool);
    ~tarkistaSaldo();
    void haeTiedot();

private slots:
    void on_btnTakaisin_clicked();
    void naytaTiedot();

private:
    Ui::tarkistaSaldo *ui;
    int korttinumero;
    int tilinumero;
    bool creditValittu;
    QTimer *objTimer;
    QNetworkAccessManager *saldoManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // TARKISTASALDO_H
