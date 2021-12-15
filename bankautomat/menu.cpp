#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
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

menu::~menu()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

void menu::paivitaLayout()                  // Päivitetään formlayout vastaamaan käytettyä korttia ja tilivalintaa
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

void menu::setKirjautumistiedot(int korttiID)   // Kirjauduttaessa sisään haetaan korttitedon perusteella muut tarvittavat käyttäjätiedot luokan muuttujiin
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

void menu::kirjaaTiedot(QNetworkReply *reply)       // Kerätään json-responsesta tiedot luokan muutujiin
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
        objVaihdaTili = new vaihdaTili(this, creditValittu);
        objVaihdaTili->setModal(true);
        creditValittu = objVaihdaTili->loginValitseTili();
        delete objVaihdaTili;
        objVaihdaTili = nullptr ;
    }
    paivitaLayout();
}

void menu::on_btnVaihdaTili_clicked()               // Nappeja panamalla ajetaan napin kuvaama ominaisuus
{
    objTimer->stop();
    objVaihdaTili = new vaihdaTili(this, creditValittu);
    objVaihdaTili->setModal(true);
    objVaihdaTili->show();
    creditValittu = objVaihdaTili->exec();
    paivitaLayout();
    delete objVaihdaTili;
    objVaihdaTili = nullptr;
    objTimer->start(30000);
}

void menu::on_btnNaytaSaldo_clicked()
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

void menu::on_btnSelaaTapahtumia_clicked()
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

void menu::on_btnNostaRahaa_clicked()
{
    objTimer->stop();
    objNostaRahaa = new nostaRahaa(this, tilinumero, creditValittu, korttiNro);
    objNostaRahaa->setModal(true);
    objNostaRahaa->show();
    objNostaRahaa->exec();
    delete objNostaRahaa;
    objNostaRahaa = nullptr;
    objTimer->start(30000);
}

void menu::on_btnTalletaRahaa_clicked()
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

void menu::on_btnTilisiirto_clicked()
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

void menu::on_btnLogout_clicked()
{
    emit kirjaaUlos();
}

