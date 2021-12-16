#include "valikko.h"
#include "ui_valikko.h"

valikko::valikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    korttiNro = 0;
    credit = 0;
    tilinumero = 0;
    idAsiakas = 0;
    creditValittu = 0;
    nimi.clear();

    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, kirjaaUlos);
    objTimer->start(30000);
}

valikko::~valikko()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

void valikko::paivitaLayout()                  // Päivitetään formlayout vastaamaan käytettyä korttia ja tilivalintaa
{
    QString tervetuloa = "Tervetuloa automaatille "+nimi;
    ui->labelTervetuloa->setText(tervetuloa);
    QString tilinro = "Tilinumero:  "+QString::number(tilinumero);
    ui->labelTilinro->setText(tilinro);
    if(creditValittu == true)
    {
        ui->labelTilityyppi->setText("Credit");
        ui->btnTalletaRahaa->setEnabled(false);
        ui->btnTalletaRahaa->setText("");
    }
    else
    {
        ui->labelTilityyppi->setText("Debit");
        ui->btnTalletaRahaa->setEnabled(true);
        ui->btnTalletaRahaa->setText("Talleta rahaa");
    }
    if(credit == 1)
    {
        ui->btnVaihdaTili->setEnabled(true);
        ui->btnVaihdaTili->setText("Vaihda tili");
    }
    else
    {
        ui->btnVaihdaTili->setEnabled(false);
        ui->btnVaihdaTili->setText("");
    }
}

void valikko::setKirjautumistiedot(int korttiID)   // Kirjauduttaessa sisään haetaan korttitedon perusteella muut tarvittavat käyttäjätiedot luokan muuttujiin
{
    QString site_url="http://localhost:3000/pankkikortti/a/";
    site_url.append(QString::number(korttiID));
    QString credentials="root:root";
    QNetworkRequest request((site_url));
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(kirjaaTiedot(QNetworkReply*)));
    reply = getManager->get(request);
}

void valikko::kirjaaTiedot(QNetworkReply *reply)       // Kerätään json-responsesta tiedot luokan muutujiin
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       korttiNro = json_obj["korttinumero"].toInt();
       credit = json_obj["credit"].toInt();
       tilinumero = json_obj["tilinumero"].toInt();
       idAsiakas = json_obj["idasiakas"].toInt();
       nimi = json_obj["nimi"].toString();
    }
    if(credit == 1)                                 // Jos kortilla on myös credit-tili kysytään kummalla tilillä kirjaudutaan ja tallennetaan tieto luokan muuttujaan
    {
        objValitseTili = new valitseTili(this, creditValittu);
        objValitseTili->setModal(true);
        creditValittu = objValitseTili->loginValitseTili();
        delete objValitseTili;
        objValitseTili = nullptr ;
    }
    paivitaLayout();
}

void valikko::on_btnVaihdaTili_clicked()               // Nappeja panamalla ajetaan napin kuvaama ominaisuus
{
    objTimer->stop();
    objValitseTili = new valitseTili(this, creditValittu);
    objValitseTili->setModal(true);
    objValitseTili->show();
    creditValittu = objValitseTili->exec();
    paivitaLayout();
    delete objValitseTili;
    objValitseTili = nullptr;
    objTimer->start(30000);
}

void valikko::on_btnNaytaSaldo_clicked()
{
    objTimer->stop();
    objSaldo = new saldo(this, tilinumero, creditValittu, korttiNro);
    objSaldo->setModal(true);
    objSaldo->show();
    objSaldo->exec();
    delete objSaldo;
    objSaldo = nullptr;
    objTimer->start(30000);
}

void valikko::on_btnSelaaTapahtumia_clicked()
{
    objTimer->stop();
    objNaytaTapahtumia = new naytaTapahtumia(this, korttiNro, tilinumero, creditValittu);
    objNaytaTapahtumia->setModal(true);
    objNaytaTapahtumia->show();
    objNaytaTapahtumia->exec();
    delete objNaytaTapahtumia;
    objNaytaTapahtumia = nullptr;
    objTimer->start(30000);
}

void valikko::on_btnNostaRahaa_clicked()
{
    objTimer->stop();
    objNosto = new nosto(this, tilinumero, creditValittu, korttiNro);
    objNosto->setModal(true);
    objNosto->show();
    objNosto->exec();
    delete objNosto;
    objNosto = nullptr;
    objTimer->start(30000);
}

void valikko::on_btnTalletaRahaa_clicked()
{
    objTimer->stop();
    objTalletaRahaa = new talletaRahaa(this, tilinumero, korttiNro);
    objTalletaRahaa->setModal(true);
    objTalletaRahaa->show();
    objTalletaRahaa->exec();
    delete objTalletaRahaa;
    objTalletaRahaa = nullptr;
    objTimer->start(30000);
}

void valikko::on_btnTilisiirto_clicked()
{
    objTimer->stop();
    objTilisiirto = new tilisiirto(this, tilinumero, creditValittu, korttiNro);
    objTilisiirto->setModal(true);
    objTilisiirto->show();
    objTilisiirto->exec();
    delete objTilisiirto;
    objTilisiirto = nullptr;
    objTimer->start(30000);
}

void valikko::on_btnLogout_clicked()
{
    emit kirjaaUlos();
}

