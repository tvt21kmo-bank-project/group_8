#include "nostarahaa.h"
#include "ui_nostarahaa.h"

nostaRahaa::nostaRahaa(QWidget *parent, int tilinro, bool luotolle, int korttiNro) :
    QDialog(parent),
    ui(new Ui::nostaRahaa)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    setupUI("alkuarvot");

    tilinumero = tilinro;
    creditValittu = luotolle;
    korttinumero = korttiNro;
    muuSummaValikko = 0;
    nostettavaSumma = 0;

    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, timerLogout);
    objTimer->start(10000);
}

nostaRahaa::~nostaRahaa()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

void nostaRahaa::setupUI(QString tila)          // Muotoillaan formin layouttia kulloisen toiminallisuuden vaiheen mukaiseksi
{
    if(tila == "alkuarvot")
    {
        muuSummaValikko = 0;
        ui->btnOtaRahat->hide();
        ui->btnOtaRahat->setStyleSheet("border-image: url(:/rahat.png)");
        ui->lineEditMuuSumma->hide();
        ui->labelMuuSumma->hide();
        ui->btn20->setEnabled(true);
        ui->btn40->setEnabled(true);
        ui->btn60->setEnabled(true);
        ui->btn100->setEnabled(true);
        ui->btn200->setEnabled(true);
        ui->btn500->setEnabled(true);
        ui->btnMuu->setEnabled(true);
        ui->btnTakaisin->setEnabled(true);

        ui->btn20->setText("20 €");
        ui->btn40->setText("40 €");
        ui->btn60->setText("60 €");
        ui->btn100->setText("100 €");
        ui->btn200->setText("200 €");
        ui->btn500->setText("500 €");
        ui->btnMuu->setText("Muu summa");
        ui->btnOtaRahat->setText("OTA RAHAT");
        ui->btnTakaisin->setText("Takaisin");
    }
    else if(tila == "muuSumma1")
    {
        muuSummaValikko = 1;
        ui->lineEditMuuSumma->clear();
        ui->btnOtaRahat->hide();
        ui->lineEditMuuSumma->show();
        ui->labelMuuSumma->show();
        ui->labelMuuSumma->setText("Syötä haluamasi rahasumma,\nväliltä 5 - 1000 €");
        ui->btn20->setEnabled(false);
        ui->btn40->setEnabled(false);
        ui->btn60->setEnabled(false);
        ui->btn100->setEnabled(false);
        ui->btn200->setEnabled(false);
        ui->btn500->setEnabled(true);
        ui->btnMuu->setEnabled(false);

        ui->btn20->setText("");
        ui->btn40->setText("");
        ui->btn60->setText("");
        ui->btn100->setText("");
        ui->btn200->setText("");
        ui->btn500->setText("Valitse summa");
        ui->btnMuu->setText("");
        ui->lineEditMuuSumma->setReadOnly(false);
    }
    else if(tila == "muuSumma2")
    {
        muuSummaValikko = 2;
        int annettuLuku = ui->lineEditMuuSumma->text().toInt();
        if( annettuLuku > 1000 || annettuLuku < 5)
        {
            ui->labelMuuSumma->setText("Virheellinen syöte!\n Syötä summa väliltä 5 - 1000 €");
            objTimer->singleShot(3500,[=]()
            {
                ui->lineEditMuuSumma->clear();
                setupUI("muuSumma1");
            });
        }
        else
        {
            // Lasketaan luku lähinpään alaspäin viidellä jaollinen summa
            annettuLuku = annettuLuku/5;
            annettuLuku = annettuLuku*5;
            ui->labelMuuSumma->setText("Suoritetaanko tililtä nosto summalla:");
            ui->lineEditMuuSumma->setText(QString::number(annettuLuku));
            ui->lineEditMuuSumma->setReadOnly(true);
            ui->btn40->setEnabled(true);
            ui->btn40->setText("Muuta summaa");
            ui->btn500->setText("Valitse");
        }
    }
    else if(tila == "loppuEvent")
    {
        ui->labelOtsikko->hide();
        ui->lineEditMuuSumma->clear();
        ui->lineEditMuuSumma->hide();
        ui->btnOtaRahat->hide();
        ui->lineEditMuuSumma->hide();
        ui->labelMuuSumma->show();
        ui->labelMuuSumma->setText("Nostoa suoritetaan...\nTarkistetaan katetta");
        ui->btn20->setEnabled(false);
        ui->btn40->setEnabled(false);
        ui->btn60->setEnabled(false);
        ui->btn100->setEnabled(false);
        ui->btn200->setEnabled(false);
        ui->btn500->setEnabled(false);
        ui->btnMuu->setEnabled(false);

        ui->btn20->setText("");
        ui->btn40->setText("");
        ui->btn60->setText("");
        ui->btn100->setText("");
        ui->btn200->setText("");
        ui->btn500->setText("");
        ui->btnMuu->setText("");
    }
}

void nostaRahaa::tarkistaKate(int valittuSumma)     // Haetaan tietokannasta tilin tiedot katteen riittävyyden tarkastusta varten
{
    setupUI("loppuEvent");

    int nostettavaSumma_int = valittuSumma;         // Laiska kun olen niin en jaksanut muuttaa aluksi valitsemaani datatyyppia jo kirjoitettuun koodiin niin vaihdetaan se nyt tässä
    nostettavaSumma = (double)nostettavaSumma_int;

    QJsonObject json;
    json.insert("id1", korttinumero);
    QString site_url = "http://localhost:3000/pankki/saldo_katsaus";
    QString credentials = "root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    atmManager = new QNetworkAccessManager(this);
    connect(atmManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(onkoKatetta(QNetworkReply*)));
    reply = atmManager->post(request, QJsonDocument(json).toJson());
}

void nostaRahaa::onkoKatetta(QNetworkReply *reply)  // Tarkastetaan riittääkö tilillä kate käyttäjän pyytämään nostotapahtumaan
{
    double saldo = 0;
    double creditSaldo = 0;
    double luottoraja = 0;
    bool tilillaKatetta = false;

    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       saldo = json_obj["saldo"].toDouble();
       creditSaldo = json_obj["creditsaldo"].toDouble();
       luottoraja = json_obj["luottoraja"].toDouble();
    }
    if(creditValittu == true)
    {
        creditSaldo = creditSaldo +luottoraja;
        if(creditSaldo >= nostettavaSumma)
        {
            tilillaKatetta = true;
        }
        else
        {
            tilillaKatetta = false;
        }
    }
    else
    {
        if(saldo >= nostettavaSumma)
        {
            tilillaKatetta = true;
        }
        else
        {
            tilillaKatetta = false;
        }
    }

    if(tilillaKatetta == true)
    {
        ui->labelMuuSumma->setText("Nostoa suoritetaan...\nKate ok tuodaan rahoja");
        objTimer->singleShot(1000,[=]()
        {
            ui->labelMuuSumma->setText("Nostoa suoritetaan...\nOta rahat");
            ui->btnOtaRahat->show();
            objTimer->start(10000);
        });
    }
    else
    {
        ui->labelMuuSumma->show();
        ui->btnTakaisin->setText("");
        ui->btnTakaisin->setEnabled(false);
        ui->labelMuuSumma->setText("Nostoa ei voida suorittaa\nTilillä ei ole riittävästi katetta\nYritä uudelleen eri rahasummalla");
        objTimer->singleShot(2500,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    reply->deleteLater();
}

void nostaRahaa::timerLogout()          // mikäli käyttäjä jumittaa 10s painamatta mitään nappia suljetaan nostotapahtuma ja palaan menuun
{
    ui->btnOtaRahat->hide();
    ui->labelMuuSumma->show();
    ui->labelMuuSumma->setText("AIKAKATKAISU!\nNostotapahtuma keskeytetty");
    objTimer->singleShot(2500,[=](){emit reject();});
}

void nostaRahaa::on_btn20_clicked()
{
    objTimer->start(10000);
    tarkistaKate(20);
}

void nostaRahaa::on_btn40_clicked()     // Napeilla suoritetaan nostettavan rahasumman valinta
{
    objTimer->start(10000);
    if(muuSummaValikko == 2)
    {
       setupUI("muuSumma1");
    }
    else
    {
    tarkistaKate(40);
    }
}

void nostaRahaa::on_btn60_clicked()
{
    objTimer->start(10000);
    tarkistaKate(60);
}

void nostaRahaa::on_btn100_clicked()
{
    objTimer->start(10000);
    tarkistaKate(100);
}

void nostaRahaa::on_btn200_clicked()
{
    objTimer->start(10000);
    tarkistaKate(200);
}

void nostaRahaa::on_btn500_clicked()
{
    objTimer->start(10000);
    if(muuSummaValikko == 2)
    {
        int x = ui->lineEditMuuSumma->text().toInt();
        tarkistaKate(x);
    }
    else if(muuSummaValikko == 1)
    {
        setupUI("muuSumma2");
    }
    else
    {
    tarkistaKate(500);
    }
}

void nostaRahaa::on_btnMuu_clicked()
{
    objTimer->start(10000);
    setupUI("muuSumma1");
}

void nostaRahaa::on_btnTakaisin_clicked()
{
    if(muuSummaValikko >= 1)
    {
        objTimer->start(10000);
        setupUI("alkuarvot");
    }
    else
    {
        this->close();
    }
}

void nostaRahaa::on_btnOtaRahat_clicked()               // Ota rahat napilla lähetetäåän tietokantaan pyyntö kirjata kyseinen nostotransaktio
{
    ui->btnOtaRahat->setEnabled(false);
    ui->btnOtaRahat->setStyleSheet("border-image:");
    ui->btnOtaRahat->setText("Rahat otettu");
    ui->btnTakaisin->setEnabled(false);

    QJsonObject json;
    json.insert("id1", korttinumero);
    json.insert("summa", nostettavaSumma);
    json.insert("luotto", creditValittu);
    QString site_url = "http://localhost:3000/pankki/otto";
    QString credentials = "root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    nostoManager = new QNetworkAccessManager(this);
    connect(nostoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(onnistuikoNosto(QNetworkReply*)));
    reply = nostoManager->post(request, QJsonDocument(json).toJson());
}

void nostaRahaa::onnistuikoNosto(QNetworkReply *reply)      // Tarkastetaan responsetiedoista onnistuiko kirjaaminen tietokantaan. Mikäli ei niin revitään käyttäjältä rahat kourasta takaisin masiinaan ja kerrotaan, että vituiks meni
{
    int onnistuiko;
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    onnistuiko = json_obj["affectedRows"].toInt();
    if(onnistuiko == 1)
    {
        ui->labelMuuSumma->setText("Nostotapahtuma onnistui");
    }
    else
    {
        ui->btnOtaRahat->setText("");
        ui->labelMuuSumma->setText("TIETOKANTAVIRHE!\nNostotapahtuma keskeytetty");
    }
    objTimer->singleShot(2500,[=](){emit accept();});
    reply->deleteLater();
}
