#include "talletarahaa.h"
#include "ui_talletarahaa.h"

talletaRahaa::talletaRahaa(QWidget *parent, int tilinro, int korttinro) :
    QDialog(parent),
    ui(new Ui::talletaRahaa)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);

    tilinumero = tilinro;
    korttinumero = korttinro;
    talletettavaSumma = 0;
    tehdytTalletukset = 0;

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

void talletaRahaa::setupUI(QString tila)        // Muotoillaan formin layouttia kulloisen toiminallisuuden vaiheen mukaiseksi. Lähinnä tulostetaan käyttäjälle viestejä
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
        objTimer->singleShot(2000,[=]()
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
        ui->labelIlmoitukset->setText(ui->labelIlmoitukset->text().append("\n\nTalletus suoritettu onnistuneesti"));
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(2000,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "virhe")
    {
        ui->labelIlmoitukset->setText("TIETOKANTAVIRHE!\nNostotapahtuma keskeytetty");
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(2000,[=]()
        {
            this->close();
        });
    }
    if(tila == "yli10k")
    {
        ui->labelIlmoitukset->setText("Talletusraja automaattitalletuksille on max 10000 € / kk\nTalletuksesi kk ajalta ovat yhteensä: "+QString::number(tehdytTalletukset).append(" €")+
                                      "\nTalletus on tehtävä asiakaspalvelun kautta");
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(3000,[=]()
        {
            setupUI("alkuarvot");
        });
    }
}

void talletaRahaa::on_btnTakaisin_clicked()
{
    this->close();
}

void talletaRahaa::on_btnTalleta_clicked()      // Ensin pyydettään tietokannasta tilille viimeisen kuukauden aikanan tehtyjen talletusten summa
{
    QString luku= ui->lineEditRahat->text();
    talletettavaSumma = luku.toDouble();

    QString site_url="http://localhost:3000/pankki/talletus_katsaus/";
    site_url.append(QString::number(tilinumero));
    QString credentials="root:root";
    QNetworkRequest request((site_url));
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    panojaManager = new QNetworkAccessManager(this);
    connect(panojaManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(talletetaanko(QNetworkReply*)));
    reply = panojaManager->get(request);

    objTimer->start(10000);
}

void talletaRahaa::talletetaanko(QNetworkReply *reply)  // Mikäli talletuksia on 10k€ kuukauden aikana ilmoitetaan käyttäjälle ettei automaattitalletus onnistu. Mikäli summa on alle suoritetaan käyttäjän pyytämä  max 5k€ talletus
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    tehdytTalletukset = json_obj["talletukset"].toDouble();

    reply->deleteLater();

    if(tehdytTalletukset > 10000)
    {
        setupUI("yli10k");
    }
    else
    {
        if(talletettavaSumma > 5000)
        {
            setupUI("liikaaRahaa");

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
        else        //  Hölmöihin pyyntöihin hölmö vastaus
        {
            ui->lineEditRahat->clear();
            setupUI("autismiaPukkaa");
        }
    }
}

void talletaRahaa::talletusTehty(QNetworkReply *reply)      // Tarkistetaan onnistuiko talletustrasaktion kirjaanen tietokantaan
{
    int onnistuiko = 0;

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
