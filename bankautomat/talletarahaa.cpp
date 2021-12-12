#include "talletarahaa.h"
#include "ui_talletarahaa.h"

talletaRahaa::talletaRahaa(QWidget *parent, int tilinro, int korttinro) :
    QDialog(parent),
    ui(new Ui::talletaRahaa)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_PaintOnScreen);
    setParent(0);
    tilinumero = tilinro;
    korttinumero = korttinro;
    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, close);
    objTimer->start(10000);
    setupUI("alkuarvot");
}

talletaRahaa::~talletaRahaa()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

void talletaRahaa::setupUI(QString tila)
{
    if(tila == "alkuarvot")
    {
        ui->btnTakaisin->setEnabled(true);
        QString alku = "Kirjauduttu tilinumerolla "+QString::number(tilinumero)+"\nTalletus suoritetaan kyseiselle tilille";
        ui->labelIlmoitukset->setText(alku);
        ui->lineEditRahat->setStyleSheet("border-image:");
    }
    if(tila == "liikaaRahaa")
    {
        QString massia = "Maksimi kertatalletus on 5000 €\nTalletettu 5000 € ja sen ylittänyt\nrahasumma palautettu talletuslokeroon";
        ui->labelIlmoitukset->setText(massia);
        QString luku= ui->lineEditRahat->text();
        double palautettavaSumma = luku.toDouble() - 5000;
        ui->lineEditRahat->setText(QString::number(palautettavaSumma));
        objTimer->singleShot(2500,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "autismiaPukkaa")
    {
        ui->lineEditRahat->setStyleSheet("border-image: url(:/tonninseteli.png);");
        objTimer->singleShot(1500,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "talletusOnnistui")
    {
        ui->labelIlmoitukset->setText("Talletus suoritettu onnistuneesti");
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(2500,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "virhe")
    {
        ui->labelIlmoitukset->setText("TIETOKANTAVIRHE!\nNostotapahtuma keskeytetty");
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(2500,[=]()
        {
            this-close();
        });
    }
}

void talletaRahaa::on_btnTakaisin_clicked()
{
    this-close();
}

void talletaRahaa::on_btnTalleta_clicked()
{
    // Lisää raja max 10k talletusta per kk //

    QString luku= ui->lineEditRahat->text();
    double talletettavaSumma = luku.toDouble();
    if(talletettavaSumma > 5000)
    {
        QJsonObject json;
        json.insert("id1", tilinumero);
        json.insert("summa", 5000);
        QString site_url = "http://localhost:3000/pankki/talletus";
        QString credentials = "root:root";
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", headerData.toLocal8Bit());
        panoManager = new QNetworkAccessManager(this);
        connect(panoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(talletusTehty(QNetworkReply*)));
        reply = panoManager->post(request, QJsonDocument(json).toJson());
        setupUI("liikaaRahaa");
    }
    else if(talletettavaSumma > 1)
    {
        ui->lineEditRahat->clear();
        QJsonObject json;
        json.insert("id1", korttinumero);
        json.insert("summa", talletettavaSumma);
        QString site_url = "http://localhost:3000/pankki/talletus";
        QString credentials = "root:root";
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", headerData.toLocal8Bit());
        panoManager = new QNetworkAccessManager(this);
        connect(panoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(talletusTehty(QNetworkReply*)));
        reply = panoManager->post(request, QJsonDocument(json).toJson());
    }
    else
    {
        ui->lineEditRahat->clear();
        setupUI("autismiaPukkaa");
    }
    objTimer->start(10000);
}

void talletaRahaa::talletusTehty(QNetworkReply *reply)
{
    int onnistuiko;
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    onnistuiko = json_obj["affectedRows"].toInt();
    if(onnistuiko == 1)
    {
        setupUI("talletusOnnistui");
    }
    else
    {
        setupUI("virhe");
    }
    reply->deleteLater();
}
