#include "pankki.h"
#include "ui_pankki.h"

pankki::pankki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pankki)
{
    ui->setupUi(this);
}

pankki::~pankki()
{
    delete ui;
}

void pankki::on_btnSiirto_clicked()
{
    QJsonObject json;
    json.insert("id1", ui->leId1->text());
    json.insert("id2", ui->leId2->text());
    json.insert("summa", ui->leSumma->text());
    QString site_url = "http://localhost:3000/bank/tilisiirto";
    QString credentials = "testi:testi";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
}

void pankki::debitSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    qDebug() << response_data;
    if(response_data == "1")
    {
        ui->labelDebitInfo->setText("Siirto onnistui!");
        ui->leId1->setText("");
        ui->leId2->setText("");
        ui->leSumma->setText("");
    }
    else
    {
        ui->labelDebitInfo->setText("Siirto epäonnistui!");
        ui->leId1->setText("");
        ui->leId2->setText("");
        ui->leSumma->setText("");
    }
}
