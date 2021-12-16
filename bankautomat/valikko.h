#ifndef VALIKKO_H
#define VALIKKO_H

#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "valitsetili.h"
#include "nostarahaa.h"
#include "naytatapahtumia.h"
#include "saldo.h"
#include "talletarahaa.h"
#include "tilisiirto.h"
#include <QDialog>

namespace Ui {
class valikko;
}

class valikko : public QDialog
{
    Q_OBJECT

public:
    explicit valikko(QWidget *parent = 0);
    ~valikko();
    void setKirjautumistiedot(int);
    void paivitaLayout();

private:
    Ui::valikko *ui;
    QByteArray response_data;
    QNetworkReply *reply;
    QNetworkAccessManager *getManager;
    nostaRahaa *objNostaRahaa;
    naytaTapahtumia *objNaytaTapahtumia;
    talletaRahaa *objTalletaRahaa;
    saldo *objSaldo;
    valitseTili *objValitseTili;
    tilisiirto *objTilisiirto;
    QTimer *objTimer;
    int korttiNro;
    int credit;
    int tilinumero;
    int idAsiakas;
    QString nimi;
    bool creditValittu;

private slots:
    void kirjaaTiedot(QNetworkReply *reply);
    void on_btnVaihdaTili_clicked();
    void on_btnNaytaSaldo_clicked();
    void on_btnSelaaTapahtumia_clicked();
    void on_btnNostaRahaa_clicked();
    void on_btnTalletaRahaa_clicked();
    void on_btnLogout_clicked();
    void on_btnTilisiirto_clicked();

signals:
    void nollaaLogoutTimer();
    void kirjaaUlos();
};

#endif // VALIKKO_H

