#include "tilisiirto.h"
#include "ui_tilisiirto.h"

tilisiirto::tilisiirto(QWidget *parent, int tilinro, bool luotolle, int korttiNro) :
    QDialog(parent),
    ui(new Ui::tilisiirto)
{
    /* Aluksi määritellään tiedot, jotka tuotiin Menu-tiedostosta.*/
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_PaintOnScreen);
    setParent(0);
    tilinumero1 = tilinro;
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
    /* setupUI vastaa ohjelman käyttöliittymästä. Eri tilat sisältävät käyttöliittymän eri
     * vaiheita. Kaikki lähtee ja palaa "alkuarvoihin", mutta kun käyttäjä tekee jotain, vaihtuu
     * myös kommentti tekstikentässä.*/
{
    if(tila == "alkuarvot")
    {
        ui->btnTakaisin->setEnabled(true);
        QString alku = "Kirjauduttu tilinumerolla "+QString::number(tilinumero1)+"\nMaksimisiirtoraja 5000e.";
        ui->textSiirto->setText(alku);
    }
    if(tila == "liikaaRahaa")
    {
        qDebug() << "Hei nyt meni liikaa rahaa! :D:";
        QString massia = "Maksimi siirtoraja on 5000 €\nSiirsimme 5000 € ja sen ylittänyt\nrahasumma on palautettu talletuslokeroon";
        ui->textSiirto->setText(massia);
        QString luku= ui->lineSumma->text();
        double palautettavaSumma = luku.toDouble() - 5000;
        ui->textSiirto->setText(QString::number(palautettavaSumma));
        objTimer->singleShot(5000,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "autismiaPukkaa")
    {
        ui->textSiirto->setText("Tilisiirto ei onnistunut\nTilinumero on väärin\ntai summa on liian suuri");
        objTimer->singleShot(5000,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "talletusOnnistui")
    {
        ui->textSiirto->setText("Siirto suoritettu onnistuneesti\nTilille jai: " +QString::number(saldoUlos));
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(5000,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "siirtoOnnistui")
    {
        ui->textSiirto->setText("Siirto tilien valilla\nsuoritettu onnistuneesti!");
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(5000,[=]()
        {
            setupUI("alkuarvot");
        });
    }
    if(tila == "virhe")
    {
        ui->textSiirto->setText("TIETOKANTAVIRHE!\nNostotapahtuma keskeytetty");
        ui->btnTakaisin->setEnabled(false);
        objTimer->singleShot(5000,[=]()
        {
            this->close();
        });
    }
}

void tilisiirto::on_btnSiirra_clicked()
{
    /* Kun käyttäjä painaa nappia Siirrä, katsotaan mitä arvoja hän on syöttänyt
    eri kenttiin. Nuo arvot määräävät sen, miten ohjelma käyttäytyy seuraavaksi
    if-lauseiden mukaan. Jos syötetty rahasumma on yli 5000 tai alle 1, tai jos
    syötetty tilinumero on väärä, ohjaa koodi "autismiaPukkaa" -UI-näkymään.*/
    double valiluku;
    checkerBoxValittu = ui->checkBox->isChecked();
    QString luku= ui->lineSumma->text();
    QString tilinumero2= ui->lineTilille ->text();
    valiluku = tilinumero2.toDouble();
    double siirrettavaSumma = luku.toDouble();

    if(tilinumero1 == valiluku && creditValittu != checkerBoxValittu)
    {
        if (creditValittu == 1)
        {
            ui->lineSumma->clear();
            QJsonObject json;
            json.insert("tilinumero1", tilinumero1);
            json.insert("summa", siirrettavaSumma);
            QString site_url = "http://localhost:3000/pankki/credit_to_debit";
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
        if (creditValittu == 0)
        {
            ui->lineSumma->clear();
            QJsonObject json;
            json.insert("tilinumero1", tilinumero1);
            json.insert("summa", siirrettavaSumma);
            QString site_url = "http://localhost:3000/pankki/debit_to_credit";
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
    }
    else if(siirrettavaSumma > 0 && siirrettavaSumma < 5000 && creditValittu == 1)
    {
        ui->lineSumma->clear();
        QJsonObject json;
        json.insert("tilinumero1", tilinumero1);
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
        ui->lineSumma->clear();
        QJsonObject json;
        json.insert("tilinumero1", tilinumero1);
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
        ui->lineSumma->clear();
        setupUI("autismiaPukkaa");
    }
    objTimer->start(30000);
}

void tilisiirto::on_btnTakaisin_clicked()
{
    this->close();
}

void tilisiirto::siirtoTehty(QNetworkReply *reply)
{
    /* Aiemmassa funktiossa vietiin käyttäjän syöttämä input HTTP-requestina
    palvelimelle, joka syöttää tiedon tietokantaan. Tietokannasta tieto palaa
    takaisin front-endiin, jolloin dataa puretaan alla olevalla koodilla. Sitten
    se pureksitaan QByteArray-muodosta järkevämpään muotoon, jolloin tuo JSON-data
    saadaan käytettäväksi. Jos tietokannan syöttämä saldoUlos-arvo on 0 tai yli,
    on tietokantakysely onnistunut ja silloin käyttäjä ohjataan talletusOnnistui
    UI-näkymään.*/
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    qDebug() << response_data;
    foreach (const QJsonValue &value, json_array)
    {
        QJsonObject json_obj = value.toObject();
        saldoUlos = json_obj["saldoUlos"].toDouble();
    }
    qDebug() << saldoUlos;
    if(saldoUlos >= 0)
    {
        setupUI("talletusOnnistui");
    }
    else if (saldoUlos == -1)
    {
        setupUI("siirtoOnnistui");
    }
    else
    {
        setupUI("virhe");
    }
    reply->deleteLater();
}
