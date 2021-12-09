#include "saldo.h"
#include "ui_saldo.h"

saldo::saldo(QWidget *parent, int tilinro, bool credit, int korttinro) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_PaintOnScreen);
    setParent(0);
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

void saldo::haeTiedot()
{
    QJsonObject json;
    json.insert("id1", tilinumero);
    QString site_url = "http://localhost:3000/pankki/tili_Katsaus";
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

void saldo::naytaTiedot(QNetworkReply *reply)
{
    qDebug()<<"Tilitiedot haettu";
    double saldo ;
    double creditSaldo ;
    QString omistajanNimi;
    QByteArray response_data = reply->readAll();
    //qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    //qDebug()<<json_doc;
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       saldo = json_obj["saldo"].toDouble();
       creditSaldo = json_obj["credit"].toDouble();
       omistajanNimi = json_obj["nimi"].toString();
    }
    QString pvm = QDate::currentDate().toString(Qt::SystemLocaleShortDate);
    ui->labelPvm->setText(ui->labelPvm->text().append(pvm));
    QString klo = QTime::currentTime().toString("hh:mm");
    ui->labelKlo->setText(ui->labelKlo->text().append(klo));
    ui->labelKorttiNumero->setText(ui->labelKorttiNumero->text().append(QString::number(korttinumero)));
    ui->labelTiliOmistaja->setText(ui->labelTiliOmistaja->text().append(omistajanNimi));
    ui->labelTilinumero->setText(ui->labelTilinumero->text().append(QString::number(tilinumero)));
    if(creditValittu == true)
    {
        double luottoraja = -5000;              // demoaa tietokannan luottorajaa
        ui->labelKorttityyppi->setText("Credit");
        ui->labelSaldo->setText(QString::number(creditSaldo-luottoraja).append(" €"));
    }
    else
    {
        ui->labelKorttityyppi->setText("Debit");
        ui->labelSaldo->setText(QString::number(saldo).append(" €"));
    }
    reply->deleteLater();
}

void saldo::on_btnTakaisin_clicked()
{
    this->close();
}


