#include "tilisiirto.h"
#include "ui_tilisiirto.h"

tilisiirto::tilisiirto(QWidget *parent, int tilinro, bool luotolle, int korttiNro) :
    QDialog(parent),
    ui(new Ui::tilisiirto)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_PaintOnScreen);
    setParent(0);
    tilinumero = tilinro;
    creditValittu = luotolle;
    korttinumero = korttiNro;
    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, close);
    objTimer->start(100000);
    setupUI("alkuarvot");
}

tilisiirto::~tilisiirto()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

void tilisiirto::setupUI(QString tila)
{
    if(tila == "alkuarvot")
    {
        ui->btnTakaisin->setEnabled(true);
        QString alku = "Kirjauduttu tilinumerolla "+QString::number(tilinumero)+"\nTalletus suoritetaan kyseiselle tilille";
        ui->textSiirto->setText(alku);
    }
    if(tila == "liikaaRahaa")
    {
        QString massia = "Maksimi kertatalletus on 5000 €\nTalletettu 5000 € ja sen ylittänyt\nrahasumma palautettu talletuslokeroon";
        ui->textSiirto->setText(massia);
        QString luku= ui->lineSumma->text();
        double palautettavaSumma = luku.toDouble() - 5000;
        ui->textSiirto->setText(QString::number(palautettavaSumma));
        objTimer->singleShot(2500,[=]()
        {
            setupUI("alkuarvot");
        });
    }
//    if(tila == "autismiaPukkaa")
//    {
//        ui->lineEditRahat->setStyleSheet("border-image: url(:/tonninseteli.png);");
//        objTimer->singleShot(1500,[=]()
//        {
//            setupUI("alkuarvot");
//        });
//    }
    if(tila == "talletusOnnistui")
    {
        ui->textSiirto->setText("Siirto suoritettu onnistuneesti\nTilille jai: " +QString::number(saldoUlos));
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(2500,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "virhe")
    {
        ui->textSiirto->setText("TIETOKANTAVIRHE!\nNostotapahtuma keskeytetty");
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(2500,[=]()
        {
            this->close();
        });
    }
}

void tilisiirto::on_btnSiirra_clicked()
{
    qDebug() << "Ei vaan tultiin sittenkin tänne :D";
    checkerBoxValittu = ui->checkBox->isChecked();
    QString luku= ui->lineSumma->text();
    QString tilinumero2= ui->lineTilille ->text();
    double siirrettavaSumma = luku.toDouble();
    if(siirrettavaSumma > 5000 && creditValittu == 1)
    {
        QJsonObject json;
        json.insert("tilinumero1", tilinumero);
        json.insert("tilinumero2", tilinumero2);
        json.insert("creditKayttaja", creditValittu);
        json.insert("creditVastaanottaja", checkerBoxValittu);
        json.insert("summa", 5000);
        QString site_url = "http://localhost:3000/pankki/credit_tilisiirto";
        QString credentials = "root:root";
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", headerData.toLocal8Bit());
        tilisiirtoManager = new QNetworkAccessManager(this);
        connect(tilisiirtoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(siirtoTehty(QNetworkReply*)));
        reply = tilisiirtoManager->post(request, QJsonDocument(json).toJson());
        setupUI("liikaaRahaa");
    }
    else if (siirrettavaSumma > 5000 && creditValittu == 0)
    {
        qDebug() << "Tultiin sittenkin tänne :D";
        QJsonObject json;
        json.insert("tilinumero1", tilinumero);
        json.insert("tilinumero2", tilinumero2);
        json.insert("creditKayttaja", creditValittu);
        json.insert("creditVastaanottaja", checkerBoxValittu);
        json.insert("summa", 5000);
        QString site_url = "http://localhost:3000/pankki/debit_tilisiirto";
        QString credentials = "root:root";
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", headerData.toLocal8Bit());
        tilisiirtoManager = new QNetworkAccessManager(this);
        connect(tilisiirtoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(siirtoTehty(QNetworkReply*)));
        reply = tilisiirtoManager->post(request, QJsonDocument(json).toJson());
        setupUI("liikaaRahaa");
    }
    else if(siirrettavaSumma > 0 && siirrettavaSumma < 5000 && creditValittu == 1)
    {
        qDebug() << "Tultiin tänne :D";
        ui->lineSumma->clear();
        QJsonObject json;
        json.insert("tilinumero1", tilinumero);
        json.insert("tilinumero2", tilinumero2);
        json.insert("creditKayttaja", creditValittu);
        json.insert("creditVastaanottaja", checkerBoxValittu);
        json.insert("summa", siirrettavaSumma);
        QString site_url = "http://localhost:3000/pankki/credit_tilisiirto";
        QString credentials = "root:root";
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", headerData.toLocal8Bit());
        tilisiirtoManager = new QNetworkAccessManager(this);
        connect(tilisiirtoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(siirtoTehty(QNetworkReply*)));
        reply = tilisiirtoManager->post(request, QJsonDocument(json).toJson());
    }
    else if(siirrettavaSumma > 0 && siirrettavaSumma < 5000 && creditValittu == 0)
    {
        qDebug() << "Tsajaijaija Tultiin sittenkin tänne :D";
        ui->lineSumma->clear();
        QJsonObject json;
        json.insert("tilinumero1", tilinumero);
        json.insert("tilinumero2", tilinumero2);
        json.insert("creditKayttaja", creditValittu);
        json.insert("creditVastaanottaja", checkerBoxValittu);
        json.insert("summa", siirrettavaSumma);
        QString site_url = "http://localhost:3000/pankki/debit_tilisiirto";
        QString credentials = "root:root";
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", headerData.toLocal8Bit());
        tilisiirtoManager = new QNetworkAccessManager(this);
        connect(tilisiirtoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(siirtoTehty(QNetworkReply*)));
        reply = tilisiirtoManager->post(request, QJsonDocument(json).toJson());
    }
    else
    {
        qDebug() << "HEHEHEHEH Tultiin sittenkin tänne :D";
        ui->lineSumma->clear();
        setupUI("autismiaPukkaa");
    }
    objTimer->start(10000);
}


void tilisiirto::on_btnTakaisin_clicked()
{
    this->close();
}

void tilisiirto::siirtoTehty(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    qDebug() << response_data;
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
    saldoUlos = json_obj["saldoUlos"].toDouble();
    }
    qDebug() << response_data;
    qDebug() << saldoUlos;
    if(saldoUlos >= 0)
    {
        setupUI("talletusOnnistui");
    }
    else
    {
        setupUI("virhe");
    }
    reply->deleteLater();
}
