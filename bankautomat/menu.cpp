#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    korttiNro = 0;
    credit = 0;
    tilinumero = 0;
    idAsiakas = 0;
    nimi.clear();
    creditValittu = 0;
}

menu::~menu()
{
    delete ui;
}

void menu::paivitaLayout()
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

void menu::setKirjautumistiedot(int korttiID)
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

void menu::kirjaaTiedot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    qDebug()<<response_data;
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
    if(credit == 1)
    {
        objVaihdaTili = new vaihdaTili(this, creditValittu);
        objVaihdaTili->setModal(true);
        creditValittu = objVaihdaTili->loginValitseTili();
        delete objVaihdaTili;
        objVaihdaTili = nullptr;
    }
    paivitaLayout();
}

void menu::on_btnVaihdaTili_clicked()
{
    objVaihdaTili = new vaihdaTili(this, creditValittu);
    objVaihdaTili->setModal(true);
    creditValittu = objVaihdaTili->exec();
    paivitaLayout();
    delete objVaihdaTili;
    objVaihdaTili = nullptr;
}

void menu::on_btnNaytaSaldo_clicked()
{
    objSaldo = new saldo(this, tilinumero, creditValittu, korttiNro);
    objSaldo->setModal(true);
    objSaldo->show();
    objSaldo->exec();
    delete objSaldo;
    objSaldo = nullptr;
}

void menu::on_btnSelaaTapahtumia_clicked()
{
    objNaytaTapahtumia = new naytaTapahtumia(this, korttiNro, tilinumero, creditValittu);
    objNaytaTapahtumia->setModal(true);
    objNaytaTapahtumia->show();
    objNaytaTapahtumia->exec();
    delete objNaytaTapahtumia;
    objNaytaTapahtumia = nullptr;
}

void menu::on_btnLogout_clicked()
{
    emit kirjaaUlos();
}

void menu::on_btnNostaRahaa_clicked()
{
    objNostaRahaa = new nostaRahaa(this, tilinumero, creditValittu, korttiNro);
    objNostaRahaa->setModal(true);
    objNostaRahaa->show();
    objNostaRahaa->exec();
    delete objNostaRahaa;
    objNostaRahaa = nullptr;
}

void menu::on_btnTalletaRahaa_clicked()
{
    objTalletaRahaa = new talletaRahaa(this, tilinumero, korttiNro);
    objTalletaRahaa->setModal(true);
    objTalletaRahaa->show();
    objTalletaRahaa->exec();
    delete objTalletaRahaa;
    objTalletaRahaa = nullptr;
}
