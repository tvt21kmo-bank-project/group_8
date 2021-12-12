#ifndef NAYTATAPAHTUMIA_H
#define NAYTATAPAHTUMIA_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QtNetwork>
#include <QNetworkAccessManager>

namespace Ui {
class naytaTapahtumia;
}

class naytaTapahtumia : public QDialog
{
    Q_OBJECT

public:
    explicit naytaTapahtumia(QWidget *parent, int, int, bool);
    ~naytaTapahtumia();
    void haeTapahtumia();
    void haeTilinTiedot();

private slots:
    void tapahtumat(QNetworkReply *reply);
    void tilitiedot(QNetworkReply *reply);
    void on_btnTakaisin_clicked();
    void on_btnEdelliset_clicked();
    void on_btnSeuraavat_clicked();

private:
    Ui::naytaTapahtumia *ui;
    int aloitusRivi;
    int korttinumero;
    int tilinumero;
    bool creditValittu;
    QTimer *objTimer;
    QNetworkAccessManager *tapahtumaManager;
    QNetworkAccessManager *tiliManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // NAYTATAPAHTUMIA_H
