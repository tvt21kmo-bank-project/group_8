#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "vaihdatili.h"
#include "nostarahaa.h"
#include "naytatapahtumia.h"
#include "saldo.h"
#include "talletarahaa.h"
#include "tilisiirto.h"
#include <QDialog>

namespace Ui {
class menu;
}
class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();
    void setKirjautumistiedot(int);
    void paivitaLayout();

private:
    Ui::menu *ui;
    QByteArray response_data;
    QNetworkReply *reply;
    QNetworkAccessManager *getManager;
    nostaRahaa *objNostaRahaa;
    naytaTapahtumia *objNaytaTapahtumia;
    talletaRahaa *objTalletaRahaa;
    saldo *objSaldo;
    vaihdaTili *objVaihdaTili;
    tilisiirto *objTilisiirto;
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

protected:

};
#endif // MENU_H
