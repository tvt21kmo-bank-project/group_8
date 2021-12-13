#include "naytatapahtumia.h"
#include "ui_naytatapahtumia.h"

naytaTapahtumia::naytaTapahtumia(QWidget *parent, int korttinro, int tilinro, bool credit) :
    QDialog(parent),
    ui(new Ui::naytaTapahtumia)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_PaintOnScreen);
    setParent(0);
    aloitusRivi = 0;
    korttinumero = korttinro;
    tilinumero = tilinro;
    creditValittu = credit;
    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, close);
    objTimer->start(10000);
    haeTapahtumia();
    haeTilinTiedot();
}

naytaTapahtumia::~naytaTapahtumia()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

void naytaTapahtumia::haeTapahtumia()
{
    QJsonObject json;
    json.insert("id1", korttinumero);
    json.insert("luotto", creditValittu);
    json.insert("alkaenRivilta", aloitusRivi);
    QString site_url = "http://localhost:3000/pankki/tilitapahtuma_katsaus";
    QString credentials = "root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    tapahtumaManager = new QNetworkAccessManager(this);
    connect(tapahtumaManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(tapahtumat(QNetworkReply*)));
    reply = tapahtumaManager->post(request, QJsonDocument(json).toJson());

    if(aloitusRivi > 0)
    {
        ui->btnEdelliset->setEnabled(true);
    }
    else
    {
        ui->btnEdelliset->setEnabled(false);
    }
}

void naytaTapahtumia::tapahtumat(QNetworkReply *reply)
{
    QString aikaleimatTuloste = "Pvm ja klo\n";
    QString summatTuloste = "Summa\n";
    QString tapahtumatTuloste = "Tapahtumatyyppi\n";
    QString maksajatTuloste = "Maksaja/saaja\n";
    int i = 0;

    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    qDebug() << response_data;
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       QString aikaleimanMuokkaus = json_obj["aikaleima"].toString();
       aikaleimanMuokkaus.replace(10, 1, " ");
       aikaleimanMuokkaus.remove(19, 5);
       aikaleimatTuloste.append(aikaleimanMuokkaus+"\n");
       summatTuloste.append(QString::number(json_obj["summa"].toDouble())+"\n");
       tapahtumatTuloste.append(json_obj["tapahtuma"].toString()+"\n");
       maksajatTuloste.append(json_obj["maksaja_saaja"].toString()+"\n");
       i++;
    }
    ui->textEditAikaleima->setText(aikaleimatTuloste);
    ui->textEditSumma->setText(summatTuloste);
    ui->textEditTapahtumatyyppi->setText(tapahtumatTuloste);
    ui->textEditMaksaja->setText(maksajatTuloste);

    if(i == 10)
    {
        ui->btnSeuraavat->setEnabled(true);
    }
    else
    {
        ui->btnSeuraavat->setEnabled(false);
    }
    reply->deleteLater();
}

void naytaTapahtumia::haeTilinTiedot()
{
    QJsonObject json;
    json.insert("id1", korttinumero);
    QString site_url = "http://localhost:3000/pankki/saldo_Katsaus";
    QString credentials = "root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    tiliManager = new QNetworkAccessManager(this);
    connect(tiliManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(tilitiedot(QNetworkReply*)));
    reply = tiliManager->post(request, QJsonDocument(json).toJson());
}

void naytaTapahtumia::tilitiedot(QNetworkReply *reply)
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
    ui->labelTilitiedot_tilinOmistaja->setText(omistajanNimi);
    ui->labelTilitiedot_tilinumero->setText(QString::number(tilinumero));
    if(creditValittu == true)
    {
        ui->labelTilitiedot_tilityyppi->setText("Credit");
        ui->labelTilitiedot_tilinSaldo->setText(QString::number(creditSaldo).append(" €"));
    }
    else
    {
        ui->labelTilitiedot_tilityyppi->setText("Debit");
        ui->labelTilitiedot_tilinSaldo->setText(QString::number(saldo).append(" €"));
    }
}

void naytaTapahtumia::on_btnTakaisin_clicked()
{
    this->close();
}

void naytaTapahtumia::on_btnEdelliset_clicked()
{
    objTimer->start(10000);
    aloitusRivi = aloitusRivi - 10;
    haeTapahtumia();
}

void naytaTapahtumia::on_btnSeuraavat_clicked()
{
    objTimer->start(10000);
    aloitusRivi = aloitusRivi + 10;
    haeTapahtumia();
}
