#include "saldo.h"
#include "ui_saldo.h"

saldo::saldo(QWidget *parent, int tilinro, bool credit, int korttinro) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);
    ui->horizontalLayoutWidget_4->setVisible(false);
    korttinumero = korttinro;
    tilinumero = tilinro;
    creditValittu = credit;
    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, close);
    objTimer->start(10000);
    haeTiedot();
}

saldo::~saldo()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

void saldo::haeTiedot()     // Lähetetään tietokantaan tilitapahtumien hakupyyntö
{
    QJsonObject json;
    json.insert("id1", korttinumero);
    QString site_url = "http://localhost:3000/pankki/saldo_katsaus";
    QString credentials = "root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    saldoManager = new QNetworkAccessManager(this);
    connect(saldoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(naytaTiedot(QNetworkReply*)));
    reply = saldoManager->post(request, QJsonDocument(json).toJson());
}

void saldo::naytaTiedot(QNetworkReply *reply)       // Tulostetaan näytölle responsena saadut tilitiedot
{
    double saldo = 0;
    double creditSaldo = 0;
    double luottoraja = 0;
    QString omistajanNimi;
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       saldo = json_obj["saldo"].toDouble();
       creditSaldo = json_obj["creditsaldo"].toDouble();
       omistajanNimi = json_obj["nimi"].toString();
       luottoraja = json_obj["luottoraja"].toDouble();
    }
    QString pvm = QDate::currentDate().toString(Qt::SystemLocaleShortDate);
    ui->labelPvm->setText(ui->labelPvm->text().append(pvm));
    QString klo = QTime::currentTime().toString("hh:mm");
    ui->labelKlo->setText(ui->labelKlo->text().append(klo));
    ui->labelKorttiNumero->setText(ui->labelKorttiNumero->text().append(QString::number(korttinumero)));
    ui->labelTiliOmistaja->setText(ui->labelTiliOmistaja->text().append(omistajanNimi));
    ui->labelTilinumero->setText(ui->labelTilinumero->text().append(QString::number(tilinumero)));
    if(creditValittu == true)       // Jos käytössä on credit kortti näytetään tilin saldo ja luottoraja. Nostettava saldo on saldo+luottoraja
    {
        ui->horizontalLayoutWidget_3->move(160, 370);
        ui->horizontalLayoutWidget_4->setVisible(true);
        ui->labelLuottoraja->setText(ui->labelLuottoraja->text().append(QString::number(luottoraja).append(" €")));
        ui->labelSaldo->setText(ui->labelSaldo->text().append(QString::number(creditSaldo).append(" €")));
        ui->labelKorttityyppi->setText("Credit");
        ui->labelNostettavaSaldo->setText(QString::number(creditSaldo+luottoraja).append(" €"));
    }
    else
    {
        ui->labelKorttityyppi->setText("Debit");
        ui->labelNostettavaSaldo->setText(QString::number(saldo).append(" €"));
    }
    reply->deleteLater();
}

void saldo::on_btnTakaisin_clicked()
{
    this->close();
}


